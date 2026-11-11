#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    while(n--){
        int a;
        char op;
        cin>>a>>op;
        while(a--)s+=op;
    }
    int cnt=0;
    int len=int(s.size())-1;
    int mid=len/2;
    for(int i=0;i<mid;i++)
        if(s[i]!=s[i+mid])
            cnt++;
    cout<<cnt;
    return 0;
}