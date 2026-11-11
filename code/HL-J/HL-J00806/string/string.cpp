#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    int n,a,nn,l,r,ans=0;
    string s1,s2;
    cin>>n;
    for(int i=1;i<=n;i++){

    	cin>>a;cin>>s1;
    	for(int i=1;i<=a;i++){
    		s2+=s1;
		}
	}
	l=0;
	r=s2.size()-1;
	while(1){
		if (l>=r){
			break;
		}
		if (s2[l]!=s2[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
return 0;
}
