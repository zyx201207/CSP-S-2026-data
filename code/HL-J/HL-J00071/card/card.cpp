#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],b[M];
signed main(){
	cin>>n>>m;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cin>>x;
		}
	}
    return 0;
}
