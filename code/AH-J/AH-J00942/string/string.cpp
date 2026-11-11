#include<bits/stdc++.h>
using namespace std;
string s="";
long long n,ans;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
long long h;
char c;
while(n--){
	cin>>h>>c;
	for(int i=1;i<=h;i++){
		s+=c;
	}
}
long long l=0,r=s.size()-1;
        while(l<=r){
	        if(s[l]!=s[r]){
		       ans++;
	        } 
	        l++;
	        r--;
        }
        cout<<ans;
return 0;
}
