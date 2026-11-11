#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    cin>>s;
    int b=s.length();
    string a;
    int l=0;
    for(int i=b;i>0;i--){
        a[b-i]=s[i];
    }
    for(int p=0;p<b;p++){
        if(a[p]==s[p] && p==b-1){
            cout<<0;
        }
        else{
            for(int j=0;j<b;j++){
                if(b%2==0){
                    if(a[j]!=a[b-j]){
                        l++;
                    }
                }
                else{
                    if(a[j]!=a[b-j-1]){
                        l++;
                    }
                }
            }
        }
    }
    cout<<l;
    return 0;
}
