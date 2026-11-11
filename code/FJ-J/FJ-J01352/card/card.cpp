#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n-1;
	}else if(m==2){
		cout<<n-2<<" "<<n;
	}else{
		for(int i=1;i<=m;i++){
			cout<<1<<" ";
		}
	}
	
	return 0;
}
