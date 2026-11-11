#include<bits/stdc++.h>
using namespace std;
int a[20100][150],n,m,k=0,ll;
bool vis[20100]={0};
int aaa[10100],l=0,b[20100];
void a_btp(int x){
	int k=0;
	for(int i=31;i>=1;i--){
		a[++k][i]=x&1;
		x/=2;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		a_btp(b[i]);
	}
	bool yy=1;
	for(int i=1;i<=31;i++){
		int p=0;
		l=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&!yy) continue;
			if(a[j][i]==1){
				p++;
				aaa[++l]=j;
			}
		}
		if(p>=m&&yy==1){
			yy=0;
			for(int j=1;j<=l;j++){
				vis[aaa[j]]=1;
			}
		}else if(p<=m&&yy==1){
			l=0;
			for(int j=1;j<=p;j++){
				aaa[i]=0;
			}
		}else if(p==m){
			for(int j=2;j<=l;j++){
				b[aaa[j]]&=b[aaa[j-1]];
			}cout<<b[aaa[l]];
			return 0;
		}
	}for(int j=2;j<=m;j++){
		b[aaa[j]]&=b[aaa[j-1]];
	}cout<<b[aaa[l]];
	return 0;
}
