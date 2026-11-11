#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	if(m==1){
		cout<<n;
	}else{
		while(m--){
			cout<<"0";
		}
	}
	return 0;
}

