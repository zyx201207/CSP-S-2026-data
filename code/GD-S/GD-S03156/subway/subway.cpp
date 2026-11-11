#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=5e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	int x[505][N],t[505][N];
	int c,n,m,d,q,a[N],k,q1,q2,bb,bb_index,cc_index,cc;
	long long ans;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)a[i]=read();
	for(int i=0;i<n;i++){
		k=read();
		for(int j=0;j<k;j++){
			x[i][j]=read();t[i][j]=read();
		}
	}
	while(q--){
		cin>>q1>>q2;
		ans=a[q1-1]+a[q2-1];
		bb=1e9,cc=1e9;
		for(int i=0;i<n;i++)ans+=t[i][i];
		cout<<ans<<endl;
	}
	return 0;
}

