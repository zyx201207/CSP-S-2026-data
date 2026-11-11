#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char c[200010];
string str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            str=str+c[i];
        }
    }
    str=" "+str;
    long long l=1,r=str.size()-1,cnt=0;
    while(l<=r){
        if(str[l]!=str[r]) cnt++;
        l++; r--;
    }
    cout<<cnt;
    return 0;
}
