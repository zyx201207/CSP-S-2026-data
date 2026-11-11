#include<bits/stdc++.h>
using namespace std;
int T,n;
long long ans;
string s,s1;
void huiwen(string ss){
	long long len=ss.size();
	for(int i=0;i<=(len-1)/2;i++){
		if(ss[i]!=ss[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>T;
    while(T--){
    	cin>>n;
    	cin>>s1;
    	for(int i=1;i<=n/2;i++){
    		s+=s1+s1;
		}
		if(n%2!=0){
			s+=s1;
		}
		
	}
	huiwen(s);
    return 0;
}
/*
6 
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/