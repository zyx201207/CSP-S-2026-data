#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,f;
char c;
ll l,n,g,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>g>>c;
		for(int j=1;j<=g;j++){
			s+=c;
			f+=c;
		}
	}
	l=s.size();
	reverse(f.begin(),f.end());
	if(f!=s){
		if(l%2==0){
			cout<<l/2;
		}else{
			cout<<l/2;
		}
	}else{
		cout<<0;
	}
	
	return 0;
}
