#include<bits/stdc++.h>
using namespace std;
char p[1000005];
int n;
int l=1,ans;
int a;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		
		cin>>a>>b;
		
		for(int j=l;j<=l+a;j++){
			p[j]=b;
		}
		l+=a;
		
	}
	for(int i=1;i<=l/2;i++){
		if(int(p[i]) != int(p[l-i]))ans++;
	}
	cout<<ans<<endl;
	return 0;
}
