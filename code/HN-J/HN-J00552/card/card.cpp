#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=5&&m<=2){
		if(m==1){
			cout<<n;
			return 0;
		}
	}
	return 0;
}
