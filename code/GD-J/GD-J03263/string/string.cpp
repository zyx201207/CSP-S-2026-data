#include<bits/stdc++.h>
using namespace std;

int n,a,sum;
char c;
string s;

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
	for(int i=0;i*2<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
