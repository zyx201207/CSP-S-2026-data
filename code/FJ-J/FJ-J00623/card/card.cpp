#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]<a[i+1]){
			cout<<a[i]<<" ";
		}
		else if(a[i]==a[i+1]){
			cout<<"1 ";
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}