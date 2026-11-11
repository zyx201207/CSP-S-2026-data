#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    cin>>n;
    char b;
    int ad=0;
    char p[100000000]={};
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>b;
        for(int i=ad;i<a;i++){
            p[i]=b;
        }
        ad+=a;
    }
    if(n=1){
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
