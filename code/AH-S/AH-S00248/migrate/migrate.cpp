#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
long long n,d,a[MAXN],cnt;
vector<long long> b[MAXN];
bool sj[MAXN];
long long sum,l,o;
bool ok(long long x,long long y){
	return y-x<=d;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		cnt=1;b[1].clear();
		for(int i=1;i<=n;i++){
			b[cnt].push_back(a[i]);
			if(a[i+1]-a[i]>d&&i!=n){
				cnt++;
				b[cnt].clear();
			}
		}
		sum=0;
		for(int i=1;i<=cnt;i++){
			int len=b[i].size();
			for(int j=0;j<len;j++) sj[j]=0;
			for(int j=0;j+3<len;j++)
				if(!ok(b[i][j],b[i][j+3])&&ok(b[i][j],b[i][j+1])&&ok(b[i][j],b[i][j+2])&&ok(b[i][j+1],b[i][j+3])&&ok(b[i][j+2],b[i][j+3]))
					sj[j+3]=1;
			if(len<4) continue;
			l=0;o=-1;
			for(int r=0;r<len;r++){
				if(sj[r]) o=r;
				if(r==len-1||(sj[r+1]&&o!=-1)){
					if(o==-1) continue;
					sum+=(o-2-l)*(r-o+1);
					while(o!=-1){
						if(sj[l+3]) o=-1;
						l++;
					}
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
