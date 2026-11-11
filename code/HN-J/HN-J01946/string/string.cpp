#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[200005],a[200005];
string f; 
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=a[i];
		for(int j=1;j<=f.size()-1;j++) b[i]=b[i]+a[i]/(10*i)%2;
		cout<<b[i]<<" ";
}
}
