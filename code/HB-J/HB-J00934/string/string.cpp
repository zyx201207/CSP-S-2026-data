#include<bits/stdc++.h>
using namespace std;
struct node{
    long long l;
    char c;
}a[2000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].c;
    }
    string s;
    for(int i=0;i<n;i++){
        for(int j=1;j<=a[i].l;j++){
            s+=a[i].c;
        }
    }
    long long n1=0;
    for(int i=0,j=s.size()-1;i<=j;i++,j--){
        if(s[i]!=s[j]) {
            n1++;
        }
    }
    cout<<n1;
    return 0;
}
