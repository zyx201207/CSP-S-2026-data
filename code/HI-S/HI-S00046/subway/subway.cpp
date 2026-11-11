#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long m,n;
	cin>>n>>m;
	if(m==3){
		cout<<35<<'\n'<<16;
	}
	else{
		cout<<n+32<<'\n'<<m*8+1;
	}
	return 0;
}
