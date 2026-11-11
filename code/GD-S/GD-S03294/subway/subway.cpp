#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,m,a[500005],c,d,q,minn,z[505][50005],tot[505],y[505][50005],s[505][50005];
void dfs(LL t,LL p,LL st,LL f){
	if(p==st){
		t+=a[st]+y[f][st];
		minn=min(minn,t);
		return;
	}
	for(int _=1;_<=n;_++){
		
		if(z[_][p]>0){
			if(f!=_&&f!=0){
				for(int i=1;i<=tot[_];i++){
					if(s[_][i]==p){
						continue;
					}
					dfs(t+y[f][s[_][i]]+y[_][s[_][i]],s[_][i],st,_);
				}	
			}
				else if(f==0){
				for(int i=1;i<=tot[_];i++){
					if(s[_][i]==p){
						continue;
					}
					if(f==_){
						dfs(t,s[_][i],st,f);
						
					}else{
						dfs(t+y[f][s[_][i]]+y[_][p],s[_][i],st,_);
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subwayl.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		LL k;
		cin>>k;
		for(int j=1,a,b;j<=k&&cin>>a>>b;j++){
			s[i][j]=a;
			y[i][a]=b;
			z[i][a]++;
			tot[i]++;
		}
	}
	while(q--){
		LL l,r;
		cin>>l>>r;
		minn=500005;
		dfs(a[l],l,r,0);
		cout<<minn<<"\n";
	}
}
	
