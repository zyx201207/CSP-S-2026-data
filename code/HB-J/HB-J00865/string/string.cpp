#include<iostream>
#include<cmath>
using namespace std;

const long long N=2e5+5;
long long n;
struct node{
    long long a;
    char c;
}str[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;++i)cin>>str[i].a>>str[i].c;
    long long ans=0;
    long long L=1,R=n;
    while(L<R){
        long long num=min(str[L].a,str[R].a);
        str[L].a-=num;
        str[R].a-=num;
        if(str[L].c!=str[R].c)ans+=num;
        if(str[L].a==0)++L;
        if(str[R].a==0)--R;
    }
    cout<<ans<<"\n";
    return 0;
}