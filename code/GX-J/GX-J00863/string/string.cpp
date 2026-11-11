#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long len=0;
    while(n--){
        int k;
        cin>>k;
        char c;
        cin>>c;
        for(int i=1;i<=k;i++){
            s+=c;
        }
        len+=k;
    }
    //cout<<s;
    long long ans=0;
    s=' '+s;
    for(int i=1,j=len;i<=j;i++,j--){
        if(s[i]!=s[j]) ans++;
    }
    cout<<ans;
}

