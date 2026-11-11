#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],p=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1]) p=0;
	}
	if(p==1){
		for(int j=1;j<=m;j++){
			if(j==m) cout<<j;
			else cout<<j<<" ";
		}
		return 0;
	}
    if(a[n]==2) cout<<n-1<<" "<<n;
    else cout<<n<<" "<<n-1;
	return 0;
}

