//GZ-S00096 ³Â¿¡Ñö 
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;


int n,ans=-1;
long long m;
long long a[N];
unsigned long long d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n); 
	if(a[n]<=100000&&a[1]>=-100000){
		for(int i=a[1];i<=a[n];i++){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(a[j]>i){
					cnt=j-1;
					break;
				}
				d[j]=i-a[j];
			}
			unsigned long long sum=0;
			bool flag=0;
			for(int j=cnt;j>=1;j--){
				sum+=d[j];
				if(sum>m){
					ans=max(ans,cnt-j);
					flag=1;
					break;
				}
			}
			if(flag==0)ans=max(ans,cnt);
		} 
		cout<<ans;
	}
	else{
		int l=1,r=n;
		int t=0;
		while(l<=r){
			int i=(l+r)/2;
			if(l==r&&t==0)t=1;
			if(l==r&&t==1)break;
			for(int j=1;j<=i;j++){
				d[j]=a[i]-a[j];
			}
			unsigned long long sum=0;
			bool flag=0;
			for(int j=i;j>=1;j--){
				sum+=d[j];
				if(sum>m){
					flag=1;
					r=i;
					break;
				}
			}
			if(flag==0){
				ans=max(ans,i);
				l=i+1;
			}
		}  	
		cout<<ans;
	}
	return 0;
}
