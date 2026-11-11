#include<bits/stdc++.h>
using namespace std;
int main(){
    int s=0,n;
    cin>>n;
    int a;
    char s1;
    string S;
    int ss=0;
    for(int i=0;i<n;i++){
        cin>>a>>s1;
        while(a>0){
            S[ss]=s1;
            a--;
        }
    }
    for(int i=0;i<ss;i++){
        if(S[ss]=!S[i]){
            s++;
        }
    }
    cout<<s;
    return 0;
}
//NOIACAC
