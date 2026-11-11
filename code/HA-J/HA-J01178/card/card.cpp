#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int s=a[0]+a[1];
	cout<<s<<" "<<a[0]<<" "<<s+a[0];
	return 0;
}
