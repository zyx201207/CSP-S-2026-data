#include<bits/stdc++.h>
using namespace std;
long long a,b,da,m[200020];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>m[i];
	}
	sort(m+1,m+1+a);
	da=m[a];
	for(int i=a;i>a-b;i--){
		da=(da&m[i]);
	}
	cout<<da;
}
