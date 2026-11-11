#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int k=1;k<=n;k++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}	
	int i=0;
	while(i<(int)s.size()/2){
		st.push(s[i]);
		i++;
	}
	if(n%2==1)i++;
	int ans=0;
	while(i<(int)s.size()){
		char x=st.top();
		st.pop();
		if(s[i]!=x)ans++;
		i++;
	}
	cout<<ans;
	return 0;
}
