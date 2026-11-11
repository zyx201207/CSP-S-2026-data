#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long n,m,a,s,d;
	cin>>n>>m>>a>>s>>d;
	while(m--){
		cout<<m+n+a+s+d;
	}
}
