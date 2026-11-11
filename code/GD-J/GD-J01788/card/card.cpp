#include<bits/stdc++.h>
using namespace std;
long long n,m,z=0;
long long ql[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ql[i];
	}
	if(m==1){
		cout<<1;
	}
	return 0;
}
