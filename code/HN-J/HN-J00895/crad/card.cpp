#include <bits/stdc++.h>
using namespace std;
long long s[100010001000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	} 
	cout<<n<<" "<<m<<""<<s[1];
	return 0;
}
