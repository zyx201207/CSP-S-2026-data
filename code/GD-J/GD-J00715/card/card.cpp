#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cout<<n<<' ';
	}
	return 0;
} 
