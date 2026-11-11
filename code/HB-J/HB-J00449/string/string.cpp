#include<bits/stdc++.h>
using namespace std;
struct node{
    int len;
    string c;
}a[220000];
string s;
int n,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i].len>>a[i].c;
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i].len;j++){
            s+=a[i].c;
        }
    }
    int l=s.size();
    for(int i=0,j=l-1;i<=j;i++,j--){
        if(s[i]!=s[j])ans++;
    }
    cout<<ans;
    return 0;
}
