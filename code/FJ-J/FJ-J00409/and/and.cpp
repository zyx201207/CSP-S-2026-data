#include<bits/stdc++.h>
using namespace std;
int a[2000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(m==1){
		
		for(int i=0;i<n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}	
	
	if(m==n)
	{
		ans==a[0];
		for(int i=1;i<n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)
					break;
				int a1145=a[i]&a[j];
				ans=max(ans,a1145);
			}
		}
		cout<<ans;
		return 0;
	}
	ans==a[0];
	for(int i=1;i<n;i++)
		ans&=a[i];
	cout<<ans;
	return 0;
}
