#include <bits/stdc++.h>
using namespace std;
string s;
int hw(int n){
    string s2;
    int x=0;
    for(int i=n-1,j=0;i>=0,j<n;i--,j++){
        s2[j]=s[i];
    }
    for(int i=0;i<n;i++){
        if(s2[i]==s[i]){
            x++;
        }

    }if(x==n){
            return 1;
        }else{
            return 0;
        }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,b=0,j=0,x=0;
    cin>>n;
    char c;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        b+=a;
        for(j;j<b;j++){
            s[j]=c;
        }
    }
    j=0;
    for(int i=b-1;i>=0;i--){
        if(i<=j){
            break;
        }
        if(hw(b)!=1){
            if(s[i]==s[j]){
                x++;
            }
            s[i]=s[j];
            j++;
        }else{
            break;
        }
    }
    cout<<j-x;
    return 0;
}
