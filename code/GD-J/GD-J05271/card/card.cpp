#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<n<<" ";
	}
	return 0;
} 
