#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;
int n;
long long ans;
long long an;
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		char b;
		cin>>num>>b;
		for(int j=1;j<=num;j++){
			a[an+j]=b;
		} 
		an+=num;
	}
	for(int i=1;i<=an/2;i++){
		if(a[i]!=a[an-i]){
			ans++;
		}
	}
	cout<<ans; 
	return 0;
}

