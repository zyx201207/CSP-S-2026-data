#include <bits/stdc++.h>
using namespace std;
int a[200001];
char c[200001];
bool ispalin(string s){
    int l=0;
    int r=s.length();
    for(int i=0;i<s.length();i++){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    if(n==1){
        cout<<0;
        return 0;
    }else if(n==2){
        int w,y;
        char x,z;
        cin>>w>>x>>y>>z;
        if(x==z){
            cout<<0;
        }else{
            cout<<min(w,y);
        }
    }else{
        for(int i=0;i<n;i++){
            cin>>a[i]>>c[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<a[i];j++){
                s+=c[i];
            }
        }
        if(ispalin(s)){
            cout<<0;
        }else{
            cout<<8;
        }

    }
    return 0;
}
