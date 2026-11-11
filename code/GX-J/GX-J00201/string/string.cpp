#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n,len=0,sum=0;
    cin>>n;
    int a[n+16];
    string b[n+16],text;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        len=len+a[i];
        for(int j=0;j<a[i];j++){
            text=text+b[i];
            }
        }
    if(len%2!=1){
        for(int k=0;k<=len/2;k++){
            if(text[len/2-k-1]==text[len/2+k])sum++;
            }
        }
    else{
        for(int l=0;l<len/2;l++){
            if(text[len/2-l]==text[len/2+l])sum++;
            }
        }
    cout<<text;
    return 0;
    }
