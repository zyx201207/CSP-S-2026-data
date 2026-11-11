#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],s[N],ans[N],p[N];
int n,m;
void solve(int l){
	memset(s,0,sizeof(s));
	memset(p,0,sizeof(p));
	int cnt=0;
	for(int i=l;i<=n;i++){
		int x=a[i];
		for(int j=1;j<=cnt;j++){
			if(s[j]==x){
				cnt=j-1;
				break;
			}
		}
		if(p[x]>0 && p[x]<=cnt) cnt=p[x]-1;
		s[++cnt]=x;
		p[x]=cnt;
	}
	for(int i=1;i<=cnt;i++){
		ans[s[i]]++;
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
