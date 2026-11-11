#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,a[200005],b;
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=b;i++){
		cout<<a[i];
	}
}

