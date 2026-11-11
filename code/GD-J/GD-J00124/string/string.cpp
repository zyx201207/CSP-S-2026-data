#include<bits/stdc++.h>
using namespace std;
long long a[1000000005];
char b[1000000005],c[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,js=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[js]=b[i];
			js++;
		}
	}
	for(int i=0;i<(js/2);i++){
		if(c[i]!=c[js-i-1]){
			s++;
		}
	}
    cout<<s;

	return 0;
}
