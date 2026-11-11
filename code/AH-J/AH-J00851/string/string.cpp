#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s="";
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s=s+c[i];
        }
    }
    unsigned long long l=0,r=s.size()-1,cnt=0;
    while(l<=r){
        if(s[l]!=s[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout<<cnt;
    return 0;
}
