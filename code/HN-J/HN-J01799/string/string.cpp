#include<bits/stdc++.h>
using namespace std;
int n,v,x;
long long ans;
char a;
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v>>a;
		for(int j=0;j<v;j++){
			s+=a;
		}
	} 
	t=s;
	for(int i=s.size()-1;i>=0;i--){
		if(t[x]!=s[i]){
			ans++;
		}
		x++;
	}
	cout<<ans/2;
	return 0;
}

