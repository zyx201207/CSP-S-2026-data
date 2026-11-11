#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cout<<a[1]-a[0];
		break;
	}
	return 0;
}
