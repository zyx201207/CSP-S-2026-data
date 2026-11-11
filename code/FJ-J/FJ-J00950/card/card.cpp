#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=235299;
int a[N];
struct cll{
	int l=0,r=0;
}cl[N]; 
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(cl[a[i]].l==0){
			cl[a[i]].l=i;
		}
		else{
			cl[a[i]].r=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<n<<" ";
	}
	return 0;
}
