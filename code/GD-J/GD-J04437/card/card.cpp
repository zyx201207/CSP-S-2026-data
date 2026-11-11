#include<bits/stdc++.h>
using namespace std;
int a[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cout<<n<<' ';
	}

	return 0;
}

