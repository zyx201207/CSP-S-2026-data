#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<m<<" ";
	for(int i=0;i<m-2;i++){
		cout<<a[i]<<" ";
	}
	cout<<n<<" ";
	return 0;
}
