#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

    int n;cin>>n;
    long long num[222222],sm=0,cnt=0;
    long long ln,rn;
    char c[222222],lc,rc;
    for(int i=1;i<=n;i++){
        cin>>num[i]>>c[i];
    }
    int p=0,q=n+1;
    for(;p<q;){
        if(ln==0){
            p++;ln=num[p];lc=c[p];
        }if(rn==0){
            q--;rn=num[q];rc=c[q];
        if(p>q)break;
        //cout<<cnt<<' '<<ln<<' '<<lc<<' '<<rn<<' '<<rc<<'\n';
        }
        if(ln<=rn){
            cnt+=ln*(lc!=rc);rn-=ln;ln=0;
        }else{
            cnt+=rn*(rc!=lc);ln-=rn;rn=0;
        }//cout<<cnt<<' '<<ln<<' '<<lc<<' '<<rn<<' '<<rc<<' '<<p<<' '<<q<<'\n';
    }
    //cout<<cnt<<' '<<ln<<' '<<lc<<' '<<rn<<' '<<rc<<' '<<p<<' '<<q<<'\n';
    cout<<cnt;

    return 0;

}
