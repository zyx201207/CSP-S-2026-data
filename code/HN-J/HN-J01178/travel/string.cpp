#include<bits/stdc++.h>
using namespace std;
string b[200009];
int n,a[200009];
int main(){
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i+1]){
			cout<<'0';
			return 0;
		}
	}
	return 0;
}
