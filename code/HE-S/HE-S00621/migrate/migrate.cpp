#include<bits/stdc++.h>
using namespace std;
long long a[5010],d,cha;
long long f[3162][3162];
int qqqq,T,n;
bool flag;
long long sc;
long long read(){
	long long k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';c=getchar();
	}
	return k*f;
}
inline void solve(){
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i==1)continue;
		int j=i-1;
		while(a[i]-a[j]<=d&&j>=1){
			f[j][i]=1;j-=1;
		}
	}
	for(int len=3;len<=n;len++)
		for(int l=1,r;l+len-1<=n;l++){
			r=l+len-1;
			if(a[r]-a[l]>d)
				for(int tt=l+1;tt<=r-1;tt++){
					f[l][r]+=f[l][tt]*f[tt][r];
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(f[i][j]==2){
				sc+=1;
//				cout<<i<<" "<<j<<'\n';
			}
	cout<<sc<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>qqqq>>T;
	for(int pppp=1;pppp<=T;pppp++){
		cin>>n>>d;flag=0;sc=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				f[i][j]=0;
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
