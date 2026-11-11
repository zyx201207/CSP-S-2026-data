#include <bits/stdc++.h>
using namespace std;
int s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==s[i-1]) f=false;
	}
	if(f==true){
		for(int i=1;i<=n;i++) cout<<s[i];
	}
	else{
		for(int i=1;i<=n;i++){
			if(s[i]!=s[i+1]) cout<<i;
		}
	}
	return 0;
}
