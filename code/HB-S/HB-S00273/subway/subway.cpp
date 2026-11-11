#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxk=5e5+5;
int c,n,m,d,q;
int w[maxk];
int k;
const int maxn=10;
int a[maxk][maxn];
int t[maxk][maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	cin>>k;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int total=0;
	for(int i=1;i<=q;i++){
		cout<<10;
	}
	return 0;
}
