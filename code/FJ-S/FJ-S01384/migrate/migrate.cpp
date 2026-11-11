#include<iostream>
#include<cstring>
using namespace std;
const int N=2e6+6;
long long a[N];
int dist[5005][5005],sol[5005][5005];
inline long long read(){
	long long x=1,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')x=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c=read(),t=read();
	while(t--){
		int n=read();
		long long d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		memset(dist,0x3f,sizeof(dist));
		memset(sol,0,sizeof(sol));
		for(int i=1;i<=n;i++)dist[i][i]=0;
		int l=1;
		for(int i=1;i<=n;i++){
			while(a[i]-a[l]>d)l++;
			for(int j=l;j<i;j++)dist[j][i]=1,sol[j][i]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=k;i++){
				for(int j=k;j<=n;j++){
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		int ans=0;
		for(int len=4;len<=n;len++){
			for(int l=1;l<=n-len+1;l++){
				int r=l+len-1;
				for(int h=l+1;h<=r-1;h++){
					if(dist[l][h]+dist[h][r]==dist[l][r]){
						sol[l][r]+=sol[l][h]+sol[h][r];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
//				cout<<sol[i][j]<<' ';
				if((sol[i][j]+1)/2==2)ans++;
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}

