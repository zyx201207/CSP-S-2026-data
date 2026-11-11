#include<bits/stdc++.h> 
using namespace std;
int ans,a,n,l;
char s[100000000005];
char sa;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>sa;
		for(int j=l;j<=l+a;j++){
			s[j]=sa;
		}
		l+=a;
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
