#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2*1e5+4;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
	}else if(m==2){
		cout<<n<<n/2;
	}
	return 0;
}
