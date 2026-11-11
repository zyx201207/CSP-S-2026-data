#include<bits/stdc++.h>
using namespace std;
string s,c;
int n,num=1,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cin>>c;
		for(int j=num;j<=num+x;j++){
			s[j]=c[0];
		}
		num+=x;
	}
	for(int i=1,j=s.size();i<=j;i++,j--){
		if(s[i]==s[j]) ans++;
	}
	cout<<s.size()-ans;
	return 0;
}
