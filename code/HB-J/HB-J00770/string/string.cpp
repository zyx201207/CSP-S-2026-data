#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct aaaaa{
    char c;
    long long a;
}s[N],sum1[N],sum2[N];//sum1->,sum2<-
long long n,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        sum1[i].a=sum1[i-1].a+s[i].a;
        sum1[i].c=s[i].c;
    }
    for(int i=n,j=1;i>=1;i--,j++){
        sum2[j].a=sum2[j-1].a+s[i].a;
        sum2[j].c=s[i].c;
    }
    long long l=0,r=0,lq=1,rq=n,srq=1;
    char lc=' ',rc=' ';
    while(lq<rq){
       // cout<<1;

        if(sum1[lq].a<sum2[srq].a){
            if(sum1[lq].c!=sum2[srq].c){
                ans=ans+(sum1[lq].a-l);
            }
            l=min(sum1[lq].a,sum2[srq].a),r=min(sum1[lq].a,sum2[srq].a);
            lq+=1;
        }
        else {
            if(sum1[lq].c!=sum2[srq].c){
                ans=ans+(sum2[srq].a-r);
            }
            l=min(sum1[lq].a,sum2[srq].a),r=min(sum1[lq].a,sum2[srq].a);
            rq--;
            srq++;
        }
    }
    cout<<ans;
    return 0;
}
