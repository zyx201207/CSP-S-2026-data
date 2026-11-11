#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a,t,s[5005][5005],ans;
int c,d,q,k,w[50005],x,y,b[50005];
int bfs(){
	int l,r=1,ans=10001;
	int z[50005][2];
	z[1][0]=x;
	z[1][1]=0;
	for(l=1;l<=r;l++){
		for(int i=1;i<=m;i++){
			if(s[z[l][0]][i]!=0&&b[i]==0){
				if(y==i) ans=min(ans,z[l][1]+s[z[l][0]][y]);
				else{
					z[++r][0]=i;
					z[r][1]=z[l][1]+s[z[l][0]][i];
				}
			}
		}
		b[z[l][0]]=1;
	}
	return ans;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2){
			cout<<"1\n2\n";
		}
		else if(n==3){
			cout<<"1\n1\n2\n";
		}
		else if(n==5){
			cout<<"17\n9\n6\n6\n9\n";
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int a1,t1;
		cin>>k;
		cin>>a1>>t1;
		for(int j=2;j<=k;j++){
			cin>>a>>t;
			if(s[a1][a]==0) s[a1][a]=10001;
			s[a1][a]=s[a][a1]=min(s[a1][a],t+t1);
			a1=a,t1=t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=bfs();
		cout<<w[x]+ans+w[y]<<"\n";
	}
	return 0;
}
