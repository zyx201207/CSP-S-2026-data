#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		if(a[i]!=a[i+1]){
			cout<<i+1<<" ";
		}
	}
	cout<<n;
	return 0;
}
