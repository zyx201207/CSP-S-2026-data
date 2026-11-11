#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c,s;
    cin>>c>>s;
    for(int i=1;i<=n;i++){
        if(c=s+1){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
