#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int s;
    cin>>s;
    if(s==1){
        cout<<0;
        return 0;
    }
    const int a[200000]={};
    char c[200000]={};
    for(int i=1;i<=s;i++){
        cin>>a[i];
        cin>>c[i];
    }
    int ans=0;
    for(int i=1;i<=s;i++){
        if(c[i]==c[i-1]){
            ans=1;
        }
    }
    if(ans==1){
        cout<<0;
        return 0;
    }
    cout<<s/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
