#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long shu[200005];
char fu[200005];

long long mshu,mx;
char mfu;
void P(long long me,long long x){
    if(fu[me]!=mfu) ans+=min(mshu,shu[me]);
    if(mshu>shu[me]){

    }else if(mshu<shu[me]){
        mx=x;
    }else mx=0;
    mshu=abs(mshu-shu[me]);

}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>m;
  //  n=0;
   // char color='!';
    for(long long i=1;i<=m;i++){
        cin>>shu[i]>>fu[i];
        //long long tmpshu;
        //char tmpfu;
       // cin>>tmpshu>>tmpfu;
       // if(tmpfu!=color){
          //  n++;
          //  shu[n]=tmpshu;
         //   fu[n]=tmpfu;
        //    color=tmpfu;
       // }else{
        //    shu[n]+=tmpshu;
      //  }
    }
    n=m;
    if(n==1){
        cout<<0;
        return 0;
    }

    long long i=1,j=n;
    while(i<=j){
        long long s1=shu[i];
        long long s2=shu[j];
        if(mshu>0){
            if(mx==1){
                P(j,2);
                j--;
            }else{
                P(i,1);
                i++;
            }
            continue;
        }else{
            if(i==j){
                i++;
                continue;
            }
            if(fu[i]!=fu[j]) ans+=min(s1,s2);

            mshu=abs(s1-s2);

            if(s1>s2){
                mfu=fu[i];
                mx=1;
            }else if(s2>s1){
                mfu=fu[i];
                mx=2;
            }
            i++;
            j--;

        }

    }
    cout<<ans;
    return 0;
}
