#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define lowbit(x) x&(-x)
#define pii pair<int,int>
using namespace std;

const int MAXN=5e5+10,MAXM=3e5+10;
int a[MAXN];
int ans[MAXM]={0}; 
int n,m; 

void Code(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		set<int> tbl;
		vector<int> v;
		for(int j=i;j<=n;j++){
			int le=tbl.size();
			tbl.insert(a[j]);v.push_back(a[j]);
			if(le==tbl.size()){
				for(int k=0;k<v.size();k++){
					if(v[k]==a[j]){
						for(int l=k;l<v.size();l++)v.pop_back();
						break;
					}
				}
				tbl.clear();
				for(int x:v)tbl.insert(x);
			}
		}
		for(int x:v)ans[x]++;
	}
	for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int t;t=1;
	while(t--)Code();
	return 0;
}

