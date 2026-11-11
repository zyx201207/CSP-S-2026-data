#include<bits/stdc++.h>
using namespace std;
int main(){
	std::ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	int n,a[10005],k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		if(n%2==0) cout<<n/2;
		else cout<<n/2+1;
	}
	else{
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
	}
	return 0; 
}
