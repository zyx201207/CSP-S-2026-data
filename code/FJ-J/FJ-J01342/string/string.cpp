#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char d,s[200005];
long long v=1,vv,u,uu;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	u=1;
	uu=n;
	while(1){
		if(a[u]>a[uu]){
			a[u]-=a[uu];
			if(s[u]!=s[uu])	vv+=a[uu];
			uu--;
		}
		else if(a[u]==a[uu]){
			if(s[u]!=s[uu])	vv+=a[uu];
			u++;
			uu--;
		}
		else{
			a[uu]-=a[u];
			if(s[u]!=s[uu]) vv+=a[u];
			u++;
		}
		if(u>uu){
			cout<<vv;
			return 0;
		}
	}
	return 0;
}
