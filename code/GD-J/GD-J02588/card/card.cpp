#include<bits/stdc++.h>
using namespace std;
const int N=2e5+500;
long long n,m,a[N],mx=-1;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
	}


	return 0;
}
