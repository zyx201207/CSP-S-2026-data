#include<bits/stdc++.h>
using namespace std;
int n,cnt,l;
string s;
void hw(string a){
    for(int i=0;i<(l+1)/2;i++){
        if(a[i]!=a[n-i+1])cnt++;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        string x;
        cin>>x;
        for(int i=1;i<=a;i++)s+=x,l++;
    }
    hw(s);
    cout<<cnt;
    return 0;
}
