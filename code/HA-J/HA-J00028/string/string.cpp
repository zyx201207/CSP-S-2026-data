#include<bits/stdc++.h>
using namespace std;
int n;
long long a[20002];
string s[20002];
string f;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
    	cin>>a[i]>>s[i];
    	for(long long j=0;j<a[i];j++){
    		f+=s[i];
    	}
    }
    for(long long i=0;i<n;i++){
    	if(f[i]!=f[f.size()-1-i]){
    		ans++;
    	}
    }
    cout<<ans;
	return 0;
}
