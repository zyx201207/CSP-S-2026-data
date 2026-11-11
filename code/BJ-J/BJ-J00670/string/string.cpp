#include<bits/stdc++.h>
using namespace std;
string o;
long long n,ans;
struct str{
    long long a;
    string c;
}q[1000005];
void gaibian(string y){
        long long j=0,k=y.size()-1;
        for(long long i=0;i<y.size()/2+1;i++){

            if(y[j]!=y[k]){
                ans++;
            }
            j++;
            k--;
        }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>q[i].a>>q[i].c;
    }
    for(long long i=0;i<n;i++){
        for(long long j=0;j<q[i].a;j++){
            o+=q[i].c;
        }
    }
    gaibian(o);
    cout<<ans;
    return 0;
}