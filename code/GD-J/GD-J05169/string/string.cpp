#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
char b[N],c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i+1]){
			cout<<0;
			return 0;
		}
	}
	cout<<2;
	return 0;
}
