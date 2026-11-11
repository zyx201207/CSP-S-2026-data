#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int n,m,f;
    cin>>n>>f>>n>>m>>n;
    for(int i=0;i<n;i++){
        cout<<(f-i)/(n-1)+m<<endl;
    }
    return 0;
}
//Q_Q
//It is too difficult
