#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r";stdin);
    //freopen("travel.out","w";stdout);
    int n;
    cin>>n;
    int a[n+1];
    string s;
    char k;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>k;
        for(int j=1;j<=a[i];j++){
            s+=k;
        }
    }
    for(int i=1;i<=length.s()/2;i++){
        if(s[i]!=s[length.s()+1-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}   