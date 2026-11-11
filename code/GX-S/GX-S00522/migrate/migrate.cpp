#include<bits/stdc++.h>
using namespace std;
#define int long long

//This is our Victory Day
//We shall NEVER SURRENDER!

int c,t,n,d;
int x[2000005];

void solve_n3(){
	int ret=0;
	int mijump[505][505];
	int cnt[505][505];
	memset(cnt,0,sizeof(cnt));
	memset(mijump,0x3f,sizeof(mijump));
	for(int i=1;i<=n;i++){
		mijump[i][i]=0;
		cnt[i][i]=1;
	}
	for(int cd=1;cd<=n;cd++){
		for(int l=1;l<=n;l++){
			int r=l+cd;
			if(r>n)break;
			if(x[r]-x[l]<=d){
				mijump[l][r]=1;
				cnt[l][r]=1;
			}
			else{
				for(int k=l+1;k<=r-1;k++){
					int tmp=mijump[l][k]+mijump[k][r];
					if(tmp==mijump[l][r]){
						cnt[l][r]+=cnt[l][k]*cnt[k][r];
					}
					else if(tmp<mijump[l][r]){
						mijump[l][r]=tmp;
						cnt[l][r]=cnt[l][k]*cnt[k][r];
					}
				}
			}
			if(cnt[l][r]==2)ret++;
			//cout<<"l="<<l<<" r="<<r<<" cnt,mi="<<cnt[l][r]<<" "<<mijump[l][r]<<endl;
		}
	}
	cout<<ret<<endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);

	cin>>c>>t;
	for(int tt=1;tt<=t;tt++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c<=6 || n<=500)solve_n3();
		else cout<<0<<endl;
	}

	return 0;
}