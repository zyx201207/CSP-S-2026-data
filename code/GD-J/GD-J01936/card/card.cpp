#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=1e8+10;

struct node{
	int a,b;
};

int n,m,maxn,maxi,xx;
 a[N],f[N];
vector<int> q;
int t;
bool v1[M];
bool v2[M];

bool cmp(node x,node y){
	return x.b<y.b;
}
bool cmp1(int x,int y){
	return x>y;
}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=n-m+1;i--){
		cout<<i<<" ";
	}
	return 0;
}
