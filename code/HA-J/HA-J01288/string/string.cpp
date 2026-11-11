#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,ans,he;
bool vis[200050];
char y[200050];
int x[200050],z[200050];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	z[1]=1;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		z[i+1]=x[i]+z[i];
		he+=x[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=x[i];
		int p=upper_bound(z+1,z+1+n,he-cnt+1)-z;
		p--;
		while(p<=n){
			if(vis[p]) break;
			if(y[p]==y[i]){
				if(z[p]>=he-cnt+1)vis[p]=1;
				p++;
				continue;
			}
			if(z[p]<he-cnt+1){
				ans+=(min(he-cnt+x[i],z[p]+x[p]-1)-he+cnt);
			}
			else{
				vis[p]=1;
				ans+=(min(he-cnt+x[i],z[p]+x[p]-1)-z[p]+1);
			}
			p++;
		}
		
	}
	cout<<ans/2;
	return 0;
}
/*
4
2 a
5 b
2 c
3 d
aabbbbbccddd
0000
0011

*/
