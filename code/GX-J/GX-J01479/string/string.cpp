#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    long long sum=0;
    string s="";
    while(n--){
	    long long a;
	    char c;
	    cin>>a>>c;
	    sum+=a;
	    for(long long i=0;i<a;i++) s+=c;
	}
	long long ans=0;
	for(long long i=0;i<=sum/2;i++){
		if(s[i]!=s[sum-1-i]) ans++;
	}
	cout<<ans<<endl;
    return 0;
}
