#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x=0;
	cin>>n;
	string s1,s2;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		string s;
		cin>>s;
		for(int j=1;j<=m;j++){
		s1=s1+s;
		s2=s+s2;
	}
	}
	for(int i=0;i<=s1.size()/2;i++){
		if(s1[i]!=s2[i]){
			x++;
		}
		
	}
	cout<<x;
    return 0;
}