#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt[55],t,ct,ans,an[55],fst,pw=1,nw,tct;
bool num[200005][55];
vector<long long>ls;//queue<long long>ls2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        t=a[i];ct=0;
        while(t>0){
            ct++;
            if(t%2){
                cnt[ct]++;
                num[i][ct]=1;
            }
            t/=2;
        }
    }
    for(int i=35;i>=1;i--){
        if(cnt[i]>=m){
            if(fst==0){
                fst=i;
                for(int j=1;j<=n;j++){
                    if(num[j][i]){
                        ls.push_back(j);
                    }
                }
                an[i]=1;
            }
            else{
                    //cout<<ls.size()<<" ";
                tct=0;//ls2.clear()
                for(int j=0;j<ls.size();j++){
                       // cout<<a[j]<<" "<<num[a[j]][i]<<endl;
                    if(num[ls[j]][i]){tct++;}
                }//cout<<i<<" "<<tct<<" "<<m<<endl;
                if(tct>=m){
                        an[i]=1;
                    //ls.clear();
                    for(int j=0;j<ls.size();j++){
                            //cout<<j<<" ";
                        if(!num[ls[j]][i]){ls.erase(ls.begin()+j);j--;}
                    }
                }

            }
        }
    }

    for(int i=1;i<=fst;i++){
            if(an[i])
        ans+=pw;
        pw*=2;
    }
    printf("%lld",ans);
    return 0;
}