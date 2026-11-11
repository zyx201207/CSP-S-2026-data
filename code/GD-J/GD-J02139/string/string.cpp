#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s="0";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int x;
	char y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s+=y;
		}	
	}
	long long  lg=s.size()-1;
	for(long long i=1;i<=lg/2;i++){
		if(s[i]!=s[lg+1-i]){
			ans++;
		}
	}
	cout<<ans;
}
