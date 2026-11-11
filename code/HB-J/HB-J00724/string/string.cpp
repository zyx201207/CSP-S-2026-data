#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c=0,k=0,j=0;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int i=0;i<a;i++){
            s[k]=b;
            k++;
            j++;
        }
    }
    for(int i=0;i<j/2;i++){
        if(s[i]!=s[k]) {
            c++;
            k-=1;
        }
    }
    cout<<c;
    return 0;
}
