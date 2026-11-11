#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int fa[N],ea[N];
int n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	fa[1]=a[1];
	for(int i=2;i<=n;i++)fa[i]=a[i]&fa[i-1];
	ea[n]=a[n];
	for(int i=n-1;i>=1;i--)ea[i]=ea[i+1]&a[i];
	for(int i=1;i<=n;i++)ans=max(ans,max(ea[i],fa[i]));
	cout<<ans;
}
