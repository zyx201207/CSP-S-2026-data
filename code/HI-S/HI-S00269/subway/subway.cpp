#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,tw[500005],a[500][500],t[500][500],k[500];
vector<int> b[500];
bool f[500],fl[500];

int dfs(int su,int en){
	if(su==en)return 0;
	if(f[su])return 99999999;
	int ans=99999999;
	f[su]=1;
	for(int i=0;i<b[su].size();i++){
		if(fl[i])continue;
		fl[i]=1;
		for(int j=0;j<k[i];j++){
			
			ans=min(dfs(a[i][j],en)+t[i][su]+t[i][a[i][j]],ans);
		}
		fl[i]=0;
	}
	f[su]=0;
	return ans;
}

int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	
	
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		scanf("%d",&tw[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][a[i][j]]);
			b[a[i][j]].push_back(i);
		}
	}
	if(n==1&&m==2){
		printf("%d",tw[0]+tw[1]+t[0][0]+t[0][1]);
	}
	if(m==1){
		printf("0");
	}
	for(int ppp=0;ppp<q;ppp++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",(dfs(x,y)+tw[x]+tw[y]));
	}
} 
