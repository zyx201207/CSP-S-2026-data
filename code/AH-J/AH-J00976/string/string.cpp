#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char a;
        cin>>x>>a;
        for(int j=1;j<=x;j++){
            s=s+a;
        }
    }
    int in=s.size();
        int r=in-1;
        int sum=0;
        for(int i=1;i<=in/2;i++){
            if(s[i]!=s[r]){
                sum++;
            }
            r--;
        }
        cout<<sum;
    return 0;
}
