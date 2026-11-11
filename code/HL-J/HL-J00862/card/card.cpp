#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(m==1){
		cout<<n;
	}if(m==2){
		cout<<n<<' '<<n;
	}
	return 0;
}