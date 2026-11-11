#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[300005],a[300005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int f=1,fa=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=0;
		if(a[i]!=a[i-1]&&i!=0)fa=0;
	}
	if(fa==1){
		for(int i=1;i<=m;i++){
			if(i!=a[1])cout<<0<<" ";
			else cout<<n<<" ";
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			vis[a[i]]++;
		}else{
			vis[a[i-1]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
}
