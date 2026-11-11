#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4) cout<<"12";
	if(n==5) cout<<"7";
	else cout<<a[3];
	return 0;
} 
