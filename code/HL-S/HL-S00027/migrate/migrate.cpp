#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
int nxt[2000010];
long long dp1[2000010],dp2[2000010];
int qwq[2000010];
void solve(){
	int n;
	long long d;
	cin>>n>>d;
	for (int i=1;i<=n;i++) cin>>x[i];
	nxt[n]=n;
	for (int i=n-1;i>=1;i--){
		nxt[i]=nxt[i+1];
		while (x[nxt[i]]-x[i]>d) nxt[i]--;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		int lnw=0,nw=i;
		while (1){
			qwq[++lnw]=nw;
			if (nxt[nw]==nw) break;
			nw=nxt[nw];
		}
		bool flag=0;
		for (int j=2;j<lnw;j++){
			int huai=0;
			if (qwq[j]>=qwq[j-1]+2){
				if (x[qwq[j+1]]-x[qwq[j]-1]<=d) huai++;
			}
			if (qwq[j]>=qwq[j-1]+3){
				if (x[qwq[j+1]]-x[qwq[j]-2]<=d) huai++;
			}
			if (huai==2) break;
			else if (huai==1 && flag) break;
			if (huai) flag=1;
			if (flag) ans+=qwq[j+1]-qwq[j];
			else if (qwq[j]>=qwq[j-1]+2) ans+=nxt[qwq[j]-1]-qwq[j];
		}
	} 
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--) solve();
	return 0;
} 

