#include<bits/stdc++.h>
using namespace std;
long long n,o,x,ans;
string s;
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
    for(long long i=1;i<=n;i++){
    	cin>>x>>a;
    	while(x!=0){
    		s[o++]=a;
    		x--;
		}
	}
	int l=0,r=o-1;
	while(l<=r){
		if(s[l]!=s[r]){
		  ans++;	
		}
		l++;
		r--;
	}
	cout<<ans;
}
