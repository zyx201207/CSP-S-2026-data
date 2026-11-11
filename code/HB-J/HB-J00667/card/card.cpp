#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],k=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) k++;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i+1]!=a[i]) cout<<i<<" ";
		}
	}
	else if(m==2){
		int f=0,s=0;
		if(a[1]==1||a[n]==1) f++;
		if(a[2]==1||a[n]==1) f++;
		if(a[1]==2||a[n]==2) s++;
		if(a[1]==2||a[n]==2) s++;
		cout<<f<<" "<<s;
	}
	return 0;
}
