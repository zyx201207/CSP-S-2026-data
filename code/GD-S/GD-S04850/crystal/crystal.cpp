#include<bits/stdc++.h> 
using namespace std;
const int MAXN=5e5+5;
int a[MAXN];
int n,m,a,ans;
int k;
cin>>n>>m;
bool cmp(int a,int b)(
	return a<b;
)
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf(%d%11d,&n,&m);
	for(int i=1;i<=n;i++){
		scanf(%d%11d,&a[i]);
	solve(1,n);
	for(int i=2;i<=n;i++){
		if(a[i]==i-1){
			a[i]==a[i-1];
		}
	}
	}

	
	return;
}