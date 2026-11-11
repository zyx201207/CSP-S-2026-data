#include<bits/stdc++.h>
using namespace std;
char s[100000005],c;
long long n,a,ans,z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1+z;j<=z+a;j++){
			s[j]=c;
		}
		z+=a;
	}
	for(int i=1;i<=z/2;i++){
		if(s[i]!=s[z-i]){
			ans++;
			//cout<<i<<' ';
		}
	}
	cout<<ans;
	return 0;
}
