#include<bits\stdc++.h>
using namespace std;

int main(){
    default("string.in","r");
    default("string.out","w");
    int n,s=0;
    string x;
    cin>>n;
    int a[n];
    string c[n];
    for(int i=0;i<=n;i++){
        cin>>a[i]>>c[i];
        s=s+c[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            cout<<0<<endel;
            return 0;
        }
    }
    if(s%2==0){
        cout<<s/2<<endl;
    }else if(s%2!=0){
        cout<<s/2-1<<endl;
    }
    return 0;
}
