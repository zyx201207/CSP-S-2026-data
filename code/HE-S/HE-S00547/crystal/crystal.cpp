#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
struct node{
	long long va,num;
};
node hang[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long t=0;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			t++;
			hang[t].va=a[i]-a[i-1];
			hang[t].num+=hang[t-1].num+1;
		}else{
			hang[t+1].num++;
		}
	}
	long long max1=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=t;j++){
			sum+=hang[j].va*(hang[j].num-i+1);
			if(sum>m){
				long long x=hang[j].num-hang[i].num+1;
				max1=max(max1,x);
				break; 
			}
		}
	}
	cout<<max1;
	return 0;
} 
