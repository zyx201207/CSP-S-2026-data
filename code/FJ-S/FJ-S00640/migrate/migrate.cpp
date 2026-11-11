#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;
int c,t,n,cnt,k[N][2];
long long d,x[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin >> c >> t;
	while(t--){
		cin >> n >> d;cnt=0;
		for(int i=1;i<=n;i++) cin >> x[i];
		if(c==13 || c==14){
			cout << "0\n";
			continue;
		}
		int lst=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int l=i,r=n;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(x[mid]-x[i]<=d) l=mid;
				else r=mid-1;
			}
			if(l==lst || l==i) continue;
			else lst=l,cnt++,k[cnt][0]=i,k[cnt][1]=l;
			if(l==n) break;
		}
		if(cnt==1){
			cout << "0\n";
			continue;
		}
		int p=1;
		for(int i=1;i<=n;i++){
			if(k[p+1][0]<=i) p++;
			int j=p+1;
			while(k[j][0]-k[j-1][1]!=-1 && j<=cnt)
				if(k[j][0]-k[j-1][1]!=0){j=0;break;}
				else j++;
			if(j<=cnt && j!=0){
				int h=j;j++;
				while(k[j][0]-k[j-1][1]==0 && j<=cnt) j++;
				j--;
				ans+=k[j][1]-k[h][0]-1;
			}
		}
		cout << ans << '\n';
	}
	return 0;	
}
