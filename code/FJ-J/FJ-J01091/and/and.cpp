#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010],maxx;
string s;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]%m==0){
			maxx=max(maxx,a[i]);
		}
	}
	cout<<maxx;
}
