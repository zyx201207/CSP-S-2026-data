#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long l=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int a;
	char w;
    while(n--){
    	cin>>a>>w;
    	for(int i=1;i<=a;i++){
    		s+=w; 		
		}
		l+=a;
	}
	for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l+1-i]) ans++;
	}
	cout<<ans;
    return 0;
	 
} 
