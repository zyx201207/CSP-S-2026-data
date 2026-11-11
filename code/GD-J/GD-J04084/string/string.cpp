#include <bits/stdc++.h>
using namespace std; 
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int sum =0;
    for(int i=0;i<n;i++){
    	int a;
		char c;
        cin>>a>>c;
    	for(int j=0;j<a;j++){
    		s[sum]=c;
    		sum++;
		}
	}
    int r=0,u=n-1;
    int bob=0;
	while(r<n){
		if(s[r] != s[n]){
			bob++;
		} 
		r++;
		u++;
	}
	cout<<bob;
	return 0;
} 
