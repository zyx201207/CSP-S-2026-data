#include <bits/stdc++.h>
using namespace std;
int n;
long long a[291199];
char c[291199];
string s;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    s="";
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]) ans+=1;
	}
    cout<<ans;
    return 0;
}








