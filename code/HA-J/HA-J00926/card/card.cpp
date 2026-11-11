#include<bits/stdc++.h>
using namespace std;
long long n,m,f=0,;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i-1]<a[i])f=1;
		else f=0;
	}if(m==1){
		cout<<n;
	}if(f==1){
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
	}
	return 0;
}
