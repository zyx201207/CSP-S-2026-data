#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char ch[200005];
string s,str="";
long long ans=0,len;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
        len+=a[i];
        for(int j=len-a[i]+1;j<=len;j++){
            s+=ch[i];
        }
    }
    str=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<=len>>1;i++){
        if(str[i]!=s[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}