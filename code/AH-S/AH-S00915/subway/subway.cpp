#include<bits/stdc++.h>
using namespace std;
int w[200000];
struct stu{
	int k;
	int a[20001];
}s[501];
int t[501][5001];
int tt[5001][5001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	memset(t,0x3f,sizeof(t));
	memset(tt,0x3f,sizeof(tt));
	int checko=-1;
	bool viso=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i].k);
		for(int j=1;j<=s[i].k;j++){
			scanf("%d",&s[i].a[j]);
			cin>>t[i][s[i].a[j]];
		}
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=s[j].k;k++){
			for(int i=k+1;i<=s[j].k;i++){
				tt[s[j].a[k]][s[j].a[i]]=tt[s[j].a[i]][s[j].a[k]]=min(tt[s[j].a[i]][s[j].a[k]],t[j][s[j].a[i]]+t[j][s[j].a[k]]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(tt[i][k]!=-1&&tt[k][j]!=-1)
				tt[i][j]=min(tt[i][j],tt[i][k]+tt[k][j]);
			}
		}
	}
	while(q--){
		int st,ai;
		cin>>st>>ai;
		cout<<tt[st][ai]+w[st]+w[ai]<<"\n";
	}
	return 0;
}

