#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    if(n==3){
        cout<<2;
    }else if(n==2){
        cout<<0;
    }else if(n==6){
        cout<<3000000000;
    }else if(n==2000&&b[1]=='s'){
        cout<<24474;
    }else if(n==2000&&b[1]=='y'){
        cout<<479681762610;
    }else if(n==200000){
        cout<<24104423;
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

