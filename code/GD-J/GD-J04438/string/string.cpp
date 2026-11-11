#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s1;
		int n1;
		cin>>n1>>s1; 
		for(int j=0;j<n1;j++)s+=s1;
	}long long len=s.size();
	long long i1=0,ii=len-1-i1;
	while(true){
		if(s[i1]!=s[ii])ans++;
		if(i1>=ii-1){
			cout<<ans;
			return 0;
		}i1++;ii--;
	}cout<<ans; 
	return 0;
} 
