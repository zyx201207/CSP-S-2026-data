#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=1,fl=0,d;
	cin>>n>>m;
	long long a[50005];
	for(long long i=1;i<=n;i++){
	
		cin>>a[i];}
		
	sort(a+1,a+n+1);	
	for(long long i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			sum++;fl=1;
			d=a[i-1];
		for(long long b=a[i-2];m>0&&b>=1;b--){
			if(m>=d-a[b]){
				m=m-d+a[b];
				sum++;

			}else{
					break;
				}
		}
			
		}if(fl==1&&a[i]!=a[d]){
			cout<<sum;
			return 0;
		}
	}cout<<sum;
	
	return 0;
}
