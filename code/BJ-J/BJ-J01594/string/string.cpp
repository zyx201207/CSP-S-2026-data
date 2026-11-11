#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    cin>>n;
    int thi=0;
    vector<char> a;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        for(int j=1;j<=x;j++){
            a.push_back(y);
        }
        thi+=x;
    }
    for(int i=0;i<=(thi-1)/2;i++){
        if(a[i]!=a[thi-i-1]) sum++;
    }
    cout<<sum;


    return 0;
}
