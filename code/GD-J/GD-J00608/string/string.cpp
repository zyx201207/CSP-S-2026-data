#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
struct sb{
	int k;
	char c;
}a[N];
map<int,char> m;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n; 
	for(int i = 1;i<=n;i++){
		cin>>a[i].k>>a[i].c;
	}
	
	if(n==1){
		cout<<0;
		return 0;
	}
	int u=1;
	for(int i = 1;i<=n;i++){
		int j=0;
		for(j = u;j<=u+a[i].k-1;j++){
			m[j]=a[i].c;
		}
		u=j;
	}
	u-=1;
//	for(int i = 1;i<=u;i++){
//		cout<<m[i];
//	}
	int cxt=0;
	if(u%2){
		cxt=u-1;
	}
	cxt=u;
	for(int i = 1;i<=u/2;i++){
		if(m[i]==m[u-i+1]){
			cxt-=2;
		}
	}
	cout<<(cxt/2);
	return 0;
}

