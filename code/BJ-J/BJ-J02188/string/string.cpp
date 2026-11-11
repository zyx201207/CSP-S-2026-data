#include<bits/stdC++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,q,a1,p;
    long long s[10000000001],s1[10000000001],s2[10000000001];
    cin>>n;
    for(int i;i<=n*2;i++){
        if(i%2==1){
            cin>>a;
            a1=a+a1;
        }if(i%2==0){
        cin>>q;
        for(int j=q1-q;i<=q1;j++)
            s[i]==q;
        }
    }
    if(a%2==1){
        for(int i;i<a/2;i++){
            s[i]=s1[i];
        }
        for(int i=a/2+1;i<a;i++){
            s[i]=s2[i];
        }
    }
    if(a%2==0){
        for(int i;i<a/2;i++){
            s[i]=s1[i];
        }
        for(int i=a/2;i<a;i++){
            s[i]=s2[i];
        }
    }
    for(int i;i<a/2;i++){
        if(s1[i]!=s2[i]){
            p++;
        }
    }
    cout<<p;
    return 0;
}
