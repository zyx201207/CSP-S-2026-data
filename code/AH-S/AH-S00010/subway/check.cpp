#include<bits/stdc++.h>
using namespace std;
long long q, a[100005], b;
int main(){
    freopen("subway3.in","r",stdin);cin>>q>>q>>q>>q>>q;
    freopen("subway3.ans","r",stdin);for(int i=1;i<=q;++i)cin>>a[i];
    freopen("subway3.out","r",stdin);
    for(int i=1;i<=q;++i){
        cin>>b;
        if(a[i]!=b){
            cout<<"WA on test "<<i<<'\n';
            cout<<"expected "<<a[i]<<", caught "<<b<<"\n";
            return 1;
        }
    }
    cout<<"all tests passed.\n";
    cout<<q<<" tests.";
    return 0;
}
