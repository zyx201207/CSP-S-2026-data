#include<bits/stdc++.h>
using namespace std;

int n;
int ans;
char a[600006];

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int num;
        char v;
        cin>>num>>v;
        for(int j=1;j<=num;j++){
            a[++cnt]=v;
            //cout<<cnt<<endl;
        }
    }
    //<<cnt;
    for(int i=1;i<=cnt/2;i++){
        int j=cnt-i+1;
        //cout<<a[i]<<" "<<a[j]<<" ";
        if(a[i]!=a[j]) ans++;
    }
    cout<<ans;

    return 0;
}
