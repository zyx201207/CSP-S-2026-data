#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","r",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m||m==1){
		for(long long i=1;i<=m;i++){
			cout<<n<<" ";
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<i<<" ";
	}
	return 0;
}
