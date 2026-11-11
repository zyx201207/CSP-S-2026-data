#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000000],b,c,d,e;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		for(int i=1;i<=n;i++){
			cout<<n<<" ";
		}
	}
	return 0;
}
