#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
string c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==2){
		if(c[1]!=c[2]){
			cout<<min(a[1],a[2]);
		}
		else cout<<0<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
