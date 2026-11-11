#include<bits/stdc++.h>
using namespace std;
const int a=10000;
int b[a]={0};
int main(){
    string zimu[a];
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,lss=1,nasa=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int ls;
        char zifu;
        cin>>ls;
        ans+=ls;
        cin>>zifu;
    }
    cout<<ans/2<<endl;
    return 0;

}
