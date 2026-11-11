#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
int c[100005];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for (int i=1;i<=n;i++){
		b+=c[i];
		if (n%0==1){
			for (int j=1;j<=n/2){
				
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (c[i]==c[i+1]){
			cout<<0;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
