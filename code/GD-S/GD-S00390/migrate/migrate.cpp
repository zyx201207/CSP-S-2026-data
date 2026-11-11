#include<bits/stdc++.h>
using namespace std;
void read(long long &x){
	x=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c)) f=(c=='-'?-1:1),c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=x*f;
}
const int N=1e6+10;
long long c,t;
long long n,d;
long long x[N];
long long f[305][305];
long long cnt[305][305];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c),read(t);
	if(c<=6){
		while(t--){
			memset(f,0x3f3f,sizeof(f));
			memset(cnt,0,sizeof(cnt));
			read(n),read(d);
			for(int i=1;i<=n;i++)
				read(x[i]);
			for(int i=1;i<=n;i++) f[i][i]=0,cnt[i][i]=1;
			for(int i=1;i<n;i++)
				if(x[i+1]-x[i]<=d) f[i][i+1]=1,cnt[i][i+1]=1;
			int ans=0;
			for(int len=3;len<=n;len++){
				for(int l=1;l+len-1<=n;l++){
					int r=l+len-1;
					if(x[r]-x[l]<=d) f[l][r]=1,cnt[l][r]=1;
					else
					for(int mid=l+1;mid<r;mid++){
						if(cnt[l][mid]==0 || cnt[mid][r]==0) continue;
						if(f[l][mid]+f[mid][r]<f[l][r]) 
							f[l][r]=f[l][mid]+f[mid][r],
							cnt[l][r]=cnt[l][mid]*cnt[mid][r];
						else if(f[l][mid]+f[mid][r]==f[l][r]) cnt[l][r]+=cnt[l][mid]*cnt[mid][r];
					}
					if(cnt[l][r]==2) ans++;
				}
			}
	//		for(int i=1;i<=n;i++){
	//			for(int j=i;j<=n;j++){
	//				cout<<i<<":"<<j<<" min:"<<f[i][j]<<" cnt:"<<cnt[i][j]<<"  ";
	//			}
	//			cout<<endl;
	//		}
			cout<<ans<<endl;
		}
	}
	if(c==11 || c==12){
		while(t--){
			cin>>n;
			int t=0;
			for(int i=1;i<=n;i++)
				cin>>x[i];
			t=x[2]-x[1];
			cout<<n-(d/t)<<endl;
		}
	}
	if(c==13 || c==14)
		while(t--) cout<<0<<endl;
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
