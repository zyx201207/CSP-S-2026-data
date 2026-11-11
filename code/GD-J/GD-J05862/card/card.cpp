#include <bits/stdc++.h>
using namespace std;

const int inf=5e5+10;
int n,m,ans[inf],card[inf],desk[inf],appst[inf];
bool ond[inf];

int f(int left){
	int nowc=0;
	for(int i=left;i<=n;i++){
		int x=card[i];
		if(ond[x]==0){
			nowc++,desk[nowc]=x;
			appst[x]=nowc,ond[x]=1;
		}
		else{
			int les=0;
			for(int d=appst[x]+1;d<=nowc;d++){
				int nc=desk[d];
				ond[nc]=0,les++;
			}nowc-=les;
		}
	}
	return nowc;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int l=1;l<=n;l++){
		int nc=f(l);
		for(int i=1;i<=nc;i++){
			ans[desk[i]]++,ond[desk[i]]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m) cout<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
