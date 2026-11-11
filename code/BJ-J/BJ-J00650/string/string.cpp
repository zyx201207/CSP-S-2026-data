#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int n;
int a[200009];
char c[200009];
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int l=s.size();
    int ans=0;
    for(int i=0;i<=l/2;i++){
        if(s[i]!=s[l-1-i])ans++;
    }
    cout<<ans;
    return 0;
}