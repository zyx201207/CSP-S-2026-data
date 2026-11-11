#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
#define int long long
int n,m;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		int f=0;
		for(int i=1;i<=n;i++){
			f=max(a[i],f);
		}cout<<f;
		return 0;
	}else if(m==n){
		int f=a[1];
		for(int i=2;i<=n;i++){
			f=(f&a[i]);
		}
		cout<<f;
	}
	return 0;
}
