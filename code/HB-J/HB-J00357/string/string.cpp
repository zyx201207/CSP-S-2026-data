#include<bits/stdc++.h>
using namespace std;
int n;
long long siz=0,num=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        siz+=a;
        while(a--)s+=c;
    }
    long long l=0,r=siz-1;
    while(l<=r){
        if(s[l]!=s[r])num++;
        l++;
        r--;
    }
    cout<<num;
    return 0;
}
