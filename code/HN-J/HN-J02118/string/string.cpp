#include<bits/stdc++.h>
using namespace std;
int S,n,a,c,l,b,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	cin>>a>>c;
	for(int i=1;i<=n;i++){
		l+=a;
	}
	string s[l];
	for(int i=1;i<=l;i++){
		cin>>s[i];
	}
	b=l/2;
	for(int i=1;i<=b;i++){
		if(s[i]!=s[l-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;	
}
