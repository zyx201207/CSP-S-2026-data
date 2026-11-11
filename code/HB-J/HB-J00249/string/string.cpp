#include<bits/stdc++.h>
using namespace std;
char s[200000005],c;
int a,n,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	b=1;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=b;j<=b+a-1;j++){
			s[j]=c;
		}
		b+=a;
	}
	long long ans=0;
	for(int i=1;i<=b/2;i++){
		if(s[i]!=s[b-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
