#include<bits/stdc++.h>
using namespace std;
int n,num;
long long cnt,ans;
char c[100000005],zm;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>zm;
		for(int j=1;j<=num;j++){
			c[++cnt]=zm;
		}
	}
	for(int i=1;i<=cnt/2;i++){
		if(c[i]!=c[cnt-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
