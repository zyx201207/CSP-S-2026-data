#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10,INF=0x2f3f3f3f;
int c,n,m,d,q;
int t[N],li[N][22][22];
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) t[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			li[i][j]=INF;
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++)
			int x=read(),li[i][x]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
		}
	}
	while(q--){
		
	}
	return 0;
}

//AH-J00835小(存疑)朋友，我在回收站捡到了你的代码
