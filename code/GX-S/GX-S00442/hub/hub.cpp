#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t,n,k;
    cin>>c>>t;
    int a[1000000]={0},b[1000000]={0};
    for(int i=0;i<t;i++){
        cin>>n>>k;
        for(int j=0;j<n;j++){
            cin>>a[i]>>b[i];
        }
        int q;
        if(n<=10){
            q=1;
            cout<<q;
        }
        q++;

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
