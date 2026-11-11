#include <iostream>
#include <cstdio>
#include <cstring>//0 1 2 3 5
using namespace std;
struct se{
    long long ks,jw;
    char z;
};
int n;
se x[200001];
long long b,ans;
int fd(long long c){
    for(int i=1;i<=n;i++){
        if(x[i].ks<=c && c<=x[i].jw)return i;
    }
}
long long cd(int c){
    return x[c].jw-x[c].ks+1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i].jw>>x[i].z;
        x[i].jw+=x[i-1].jw;
        x[i].ks=x[i-1].jw+1;
    }
    long long c=(x[n].jw+1)/2;
    int f=fd(c);
    int x1=1,x2=n;
    long long s1=cd(x1),s2=cd(x2);
    for(int i=1;i<=n;i++){
        //cout<<1145147891<<' '<<x1<<' '<<x2<<' '<<s1<<' '<<s2<<endl;
        long long ss=min(s1,s2) ;
        if(x[x1].z!=x[x2].z){ans+=ss;}
        if(s1>s2){
            x2--;
            s1-=s2;
            s2=cd(x2);
        }
        else if(s1<s2){
            x1++;
            s2-=s1;
            s1=cd(x1);
        }
        else{
            x1++,x2--;
            s1=cd(x1),s2=cd(x2);
        }
        if(x1>=x2)break;
    }
    cout<<ans;
    return 0;
}
