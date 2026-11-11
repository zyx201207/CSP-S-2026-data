#include<bits/stdc++.h>
using namespace std;
long long n,sum,all,b[200005],bs,be,si,ei;
char c[200005],cs,ce;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i]>>c[i];
        all+=b[i];
    }
    si=1;
    ei=1;
    for(int i=1;i<=all/2;i++){
        if(bs==0){
            bs=b[si];
            cs=c[si];
            si++;
        }
        if(be==0){
            be=b[n-ei+1];
            ce=c[n-ei+1];
            ei++;
        }
        if(cs!=ce)sum++;
        bs--;
        be--;
    }
    cout<<sum;
    return 0;
}
