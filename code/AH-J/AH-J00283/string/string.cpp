#include<bits/stdc++.h>
using namespace std;
int d;
long long ans,j=1,c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>d;
	
	while(d--){
		int n;
		char a;
		scanf("%d",&n);
		cin>>a;
		c+=n;
		for(;j<=c;j++){
			s[j]=a;
		}
	}
	for(long long i=1;i<=c/2;i++){
		if(s[i]!=s[c-i+1]){
			ans++;
		}
	}
	cout<<ans;
}
