#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=1;
	for(int i=1;i<=n;i++){
		if(a[i]>t){
			cout<<i-1<<" ";
			t=a[i];
		}
	}
	cout<<n;
	return 0;
}
