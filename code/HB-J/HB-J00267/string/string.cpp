#include<bits/stdc++.h>
using namespace std;
long long n;
long long len;
long long cnt;
bool zs;
long long bj;
struct node{
    long long a;
    char c;
}ar[200005],b[200005],k;
bool pd(){
    for(long long i=1;i<=len/2;i++){
        if(!(b[i].a==b[len-i+1].a&&b[i].c==b[len-i+1].c)){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>ar[i].a>>ar[i].c;
    }
    for(long long i=1;i<=n-1;i++){
        if(ar[i].c==ar[i+1].c){
            ar[i+1].a+=ar[i].a;
            ar[i].a=0;
        }
    }
    for(long long i=1;i<=n;i++){
        if(ar[i].a==0){
            continue;
        }
        b[++len].a=ar[i].a;
        b[len].c=ar[i].c;
    }
 /*   for(long long i=1;i<=len;i++){
        cout<<b[i].a<<' '<<b[i].c<<endl;
    }
*/
    if(pd()){
        cout<<0;
        return 0;
    }
    for(long long i=1;i<=len/2+1;i++){
        if(k.a==0){
        k.a=b[i].a;
        k.c=b[i].c;
        }
        if(zs==0){
            if(k.c==b[len-i+1].c){
                if(k.a>b[len-i+1].a){
                    k.a-=b[len-i+1].a;
                }
                else{
                    k.a=b[len-i+1].a-k.a;
                    zs=1;
                }
                continue;
            }
            if(k.a>b[len-i+1].a){
                cnt+=b[len-i+1].a;
                b[len-i+1].c=k.c;
                k.a-=b[len-i+1].a;
            }
            else{
                cnt+=k.a;
                k.c=b[len-i+1].c;
                k.a=b[len-i+1].a-k.a;
                zs=1;
            }
        }
        else{
            if(k.c==b[i].c){
                if(k.a>b[i].a){
                    k.a-=b[i].a;
                }
                else{
                    k.a=b[i].a-k.a;
                    zs=0;
                }
                continue;
            }
            if(k.a>b[i].a){
                cnt+=b[i].a;
                b[i].c=k.c;
                k.a-=b[i].a;
            }
            else{
                cnt+=k.a;
                k.c=b[i].c;
                k.a=b[i].a-k.a;
                zs=0;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
