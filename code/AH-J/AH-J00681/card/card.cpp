#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int M=5e5+10;
int n,a[M];
int t[N],tmp[N],mx,m,mn[N];
int mxi,m2x,m2i;
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<i<<" ";
	}
	return 0;
}
