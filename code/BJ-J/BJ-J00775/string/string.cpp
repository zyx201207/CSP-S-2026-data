#include<bits/stdc++.h>
using namespace std;
string s,s1;
int a;
char a1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int len=0;
    for(int i=1;i<=n;i++){

        cin>>a>>a1;
        len+=a;
        while(a--){
            s+=a1;
        }
    }
    int cnt=0;
    int l=0,r=len-1;
    while(l<r){
        if(s[l]!=s[r]) cnt++;
        l++;
        r--;
    }

    cout<<cnt;
    return 0;
}
