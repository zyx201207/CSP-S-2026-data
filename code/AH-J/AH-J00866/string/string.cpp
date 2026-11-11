#include<bits/stdc++.h>
using namespace std;
bool is_palindromic(string s){
    for(size_t i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-i-1])
	    return false;
    return true;
}
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        int x;char c;
	cin>>x>>c;
	cout<<0;
	return 0;
    }else if(n==2){
        int x;char c;
	cin>>x>>c;
	string s=string(x,c);
	cin>>x>>c;
	s+=string(x,c);
	if(is_palindromic(s)) cout<<0;
	else cout<<x;
    }
    return 0;
}
