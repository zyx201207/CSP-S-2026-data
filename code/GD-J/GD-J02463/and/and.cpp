#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mn=1073741830;
int a[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int x=n;
	bool f=1;
	while(x!=1){
		if(x%2==1){
			f=0;
			break;
		}
		x/=2;
	}
	if(f){
		cout<<n-m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		mn=min(a[i],mn);
	}
	if(m==1){
		cout<<mn;
		return 0;
	}
	cout<<mn;
	return 0;
}
