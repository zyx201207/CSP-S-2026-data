#include<bits/stdc++.h>
using namespace std;
long long ans,a[20005];
int b[20005]={},n,m,pp;
void find()
{
	pp=0;
	long long sum;
	for(int i=1;i<=n;i++){
		if(b[i]!=1){
			if(pp==0){
				sum=ans&a[i];
				pp=i;
			}
			else{
				if(ans&a[i]>sum){
					pp=i;
					sum=ans&a[i];
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		ans=0;
		for(int i=1;i<n;i++){
		    for(int j=i+1;j<=n;j++){
		    	ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	long long anss=0;
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		ans=a[i];
		b[i]=1;
		for(int j=1;j<m;j++){
			find();
			b[pp]=1;
		}
		anss=max(ans,anss);
	}
	cout<<anss;
	return 0;
}
