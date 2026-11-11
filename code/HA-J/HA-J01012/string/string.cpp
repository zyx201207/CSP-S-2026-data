#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,l=0;
string s="";
long long ans=0;
struct node{
	int a;
	char c;
}x[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].c;
		l+=x[i].a;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x[i].a;j++){
			s+=x[i].c;
		}
	}
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i-1]){
			ans++;
		}
	}
	if(ans==0){
		cout<<ans;
	}
	else{
		cout<<ans+1;
	}
	return 0;
}
