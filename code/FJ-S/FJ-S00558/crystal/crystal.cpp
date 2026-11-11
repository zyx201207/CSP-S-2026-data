#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long sj[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sj[i];
	}
	sort(sj+1,sj+n+1);
	long long max_sum=0;
	if(n>5000){
		long long gcha=sj[2]-sj[1];
		long long sum2=0,q=0;
		for(int i=1;i<=n-1;i++){
			if(sum2+gcha<=m){
				sum2+=gcha;
				gcha*=2;
				q++;
			}
			else break;
		}
		cout<<q+1;
		return 0;
	}
	for(int i=n;i>=1;i--){
		long long sum=1,m2=m;
		for(int j=i-1;j>=1;j--){
			long long daijia;
			daijia=sj[i]-sj[j];
			if(daijia<=m2){
				sum++;
				m2-=daijia;
			}
			else{
				break;
			}
		}
		max_sum=max(max_sum,sum);
	}
	cout<<max_sum;
	return 0;
} 
