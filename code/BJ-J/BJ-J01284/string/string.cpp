#include<bits/stdc++.h>
using namespace std;
int n,mx=0,mxi=0;
int a[200005];
char s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        if(a[i]>mx){
            mx=max(mx,a[i]);
            mxi=i;
        }
    }
    string s1;
    for(int i=1;<=n;i++){
        for(int j=1;j<=a[i];j++){
            s1+=s[i];
        }
    }
    string s2;
    s2=reverse(s1.begin(),s1.end());
    if(s1==s2){
        cout<<0;
        return 0;
    }

    
    fclose("string.in","r",stdin);
    fclose("string.out","w",stdout);
}
