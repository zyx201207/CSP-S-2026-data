#include <bits/stdc++.h>
using namespace std;
long long n,a[100000005];
char c[200005];
string S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for (int j=1;j<=a[i];j++){
			S+=c[i];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=n;j>=1;j--){
			if (S[i]==S[j]){
				if (i==n&&j==1){
					cout<<0;
				}
			}
		}
	}
	return 0;
}
