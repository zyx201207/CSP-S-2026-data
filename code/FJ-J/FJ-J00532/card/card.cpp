#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long m=0,n;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int qm=0,zh=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cout<<n-i<<" ";
	}
}
