#include<bits/stdc++.h>
using namespace std;
int n,c1=0,c2=0;
long long int l[1000000000];
string s[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		cin>>s[i];
	}
	int o;
	for(int i=1;i<=n;i++){
		if(s[i]==s[n+1-i]){
			o=abs(l[i]-l[n+1-i]);
			c1+=o;
		}else{
			c1+=l[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]==s[n+1-i]){
			o=abs(l[i]-l[n+1-i]);
			c2+=o;
		}else{
			c2+=l[n+1-i];
		}
	}
	if(c1>c2){
		cout<<c1;
	}else{
		cout<<c1;
	}
	return 0;
}
