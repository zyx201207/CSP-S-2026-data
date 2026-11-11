#include<bits/stdc++.h>

using namespace std;
long long n,ls1,ls5;
long long a[100000009];
char x[100000009];
string s;
void cl1(){
    long long ls2=ls1/2;
    string ls3,ls4;
    for(int i=1;i<=ls2;i++){
        ls3[i]=s[i];
    }
    for(int i=ls1;i>=ls2+2;i--){
        ls4[i]=s[i];
    }
    for(int i=1;i<=ls2;i++){
        if(ls3[i]!=ls4[i]){
            ls5++;
        }
    }
    cout<<ls5;
}
void cl2(){
    long long ls2=ls1/2;
    string ls3,ls4;
    for(int i=1;i<=ls2;i++){
        ls3[i]=s[i];
    }
    for(int i=ls1;i>=ls2+1;i--){
        ls4[i]=s[i];
    }
    for(int i=1;i<=ls2;i++){
        if(ls3[i]!=ls4[i]){
            ls5++;
        }
    }
    cout<<ls5;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>x[i];
        for(int j=1;j<=a[i];j++){
            s[ls1+j]=x[i];
        }
        ls1+=a[i];

    }
    bool ls6=1;
    for(int i=1;i<=ls1;i++){
        if(s[i]==s[ls1-i+1]){
            ls6=1;
        }
        else{
            ls6=0;
            break;
        }
    }
    if(ls6==1){
        cout<<"0";
        return 0;
    }
    if(ls1%2!=0){
        cl1();
    }
    else{
        cl2();
    }
    return 0;
}
