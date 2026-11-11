#include <bits/stdc++.h>
using namespace std;
int n;
int a;
char c[10001];
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c[i];
		if(c[i]==c[i+1]){
			ans++;
		}
	}
	cout<<ans;
//	if(ans+1==n){
//		cout<<"0";
//	}
	return 0;
}
//2
//2 a
//3 a
