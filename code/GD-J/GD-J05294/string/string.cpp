#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
string st;
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>ch;
		while(a--)st=st+ch;
	}
	for(int i=0;i<st.size()/2;i++){
		if(st[i]!=st[st.size()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
