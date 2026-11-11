#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10005],cnt=0;
char c[10005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
	    cin>>a[i]>>c[i];
	    for(int j=0;j<a[i];j++){
		    s=s+c[i];
	    }
    }
    ll l=0,r=s.size()-1;
    while(l<r){
	    if(s[l]!=s[r]){
		    cnt++;
	    }
	    l++;
	    r--;
    }
    cout<<cnt;
    return 0;
}
