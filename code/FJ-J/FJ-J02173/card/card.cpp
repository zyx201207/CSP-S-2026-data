#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>

using namespace std;

bool b[300005];
int num[300005];
int ans[300005];
int qp[300005];
int cnt;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int sum;
	scanf("%d%d",&n,&m);
	int x;
	for(int i=n;i>=1;i--) scanf("%d",&num[i]);
	for(int j=1;j<=n;j++){
		for(int i=j;i>=1;i--){
			x=num[i];
			if(b[x]==true)
				while(cnt && qp[cnt]!=x){
					b[qp[cnt]]=false;
					qp[cnt--]=0;
				}
			else{
				b[x]=true;
				qp[++cnt]=x;
			}
		}
		for(int k=cnt;k>=1;k--) ans[qp[k]]++,qp[k]=0;
		cnt=0;
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
}