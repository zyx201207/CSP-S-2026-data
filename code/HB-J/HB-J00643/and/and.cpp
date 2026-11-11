#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int vis[200005];
long long ans=0;
int pp(int b,int p){
    int cnt=0;
	for(int i=1;i<=n;i++) if(a[i]%b<=a[i]/2 && vis[i]>=p && a[i]!=0){
		cnt++;
		a[i]-=b;
		vis[i]++;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int b=1;
    while(b<a[n]) b*=2;
    b/=2;int p=0;
    while(b>=1){
		if(pp(b,p)>=m) p++,ans+=b;
		b/=2;
	}
	cout<<ans;
    return 0;
}
