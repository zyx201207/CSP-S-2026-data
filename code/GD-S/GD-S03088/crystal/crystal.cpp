#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,mi,ans=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n+5],b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(int i=n;i>1;i--)
	{
		l=1,r=i-1;
		while(r>l)
		{
			mi=(r-l)/2+l;
			if(b[i-1]-b[mi-1]+mi<a[i]*(i-mi)){
				l=mi+1;
			}
			else{
				r=mi-1;
			}
			ans=max(r-l+1,ans);
		}	
	}
	cout<<++ans;
	return 0;
}
