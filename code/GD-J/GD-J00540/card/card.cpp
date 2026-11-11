#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int vis[N],ans;
int l;
string s;
int main()
{
	fre("card");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l=0;ans=0;
		for(int j=1;j<=m;j++){
			l++;
			if(vis[a[j]]){
				s="";
				l=1;
				s[l]=char(a[j]+48);
			}else{
				s[l]=char(a[j]+48);
				vis[a[j]]=1;
			}
		}
		for(int j=1;j<=l;j++){
			if(i==int(s[j])-48){
				ans++;
			}
		}
		cout<<ans<<" ";
	}
}
