#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		if(n%2==0){
			cout<<n/2;
		}else{
			cout<<n/2+1;
		}
		return 0;
	}
		return 0;
	
	
}
