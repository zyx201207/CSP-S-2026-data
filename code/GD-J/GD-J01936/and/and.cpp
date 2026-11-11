#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=1e8+10;

struct node{
	int a,b;
};

int n,m,maxn,maxi,xx;
node a[N],f[N];
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
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		if(maxn<a[i].a){
			maxn=a[i].a;
			maxi=i;
		}
	}
	//cout<<a[n].a<<endl;
	for(int i=1;i<=n;i++){
		if(v1[a[i].a]) v2[a[i].a]=1,q.push_back(a[i].a),xx++;
		v1[a[i].a]=1;
		if(i==maxi) continue;
		a[i].b=maxn-(maxn & a[i].a);
	}
	sort(q.begin(),q.end(),cmp1);
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=m;i++){
		if(maxn&a[i].a==0){
			++m;
			continue;
		}
		//cout<<(a[i].a&maxn)<<endl;
		maxn&=a[i].a;
	}
	if(maxn==0){
		cout<<q[0];
		return 0;
	}
	cout<<maxn;
	return 0;
}
