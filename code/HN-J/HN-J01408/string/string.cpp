#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string s="";
    long long int n,m,ans=0,cnt=0;
    char a;
    cin>>n;
    for(int i=0;i<n;i++){
    cin>>m>a;
    for(int j=0;j<m;j++){
    s+=a;
	}
	}
	for(int i=0;i<s.size()/2;i++){
	int j=s.size()-i-1;
	if(s[i]!=s[j]){
	ans++;
	}
	}
	cout<<ans;
	return 0;
} 
