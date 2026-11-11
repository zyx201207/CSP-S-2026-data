//GZ-J00670 兴义市弘毅中学 罗金浩 
#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500050],i,b[500050],k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	k=n;
	for(i=n;i>=1;i--){
		k--;
		b[a[i]]=n-k;
	}
	for(i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
