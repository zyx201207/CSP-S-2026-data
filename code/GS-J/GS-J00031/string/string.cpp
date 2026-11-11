#include <bits/stdc++.h>;
using namespace std;
string c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int b[n+5];
	cin>>n;
	for(int i=1;i<=n+1;i++){
		cin>>c[i];
	}
	if(n%2==0)
		cout<<n/2;
	else
		cout<<n/2+1;
	return 0;
}
