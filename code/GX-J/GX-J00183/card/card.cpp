#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int ans[500005];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		ans[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<n<<" ";
	}
//	int x=1;
//	while(x<=n){
//		for(int i=x;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(
//		}
	return 0;
}
