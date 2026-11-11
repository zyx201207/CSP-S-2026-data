#include<bits/stdc++.h>
using namespace std;
int n,m,a;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	int f=1,m=s.size();
	if(m==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<m;i++){
		if(s[i]!=s[m-i-1]){
			f=0;
		}
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	cout<<n/2;
	return 0;
}
