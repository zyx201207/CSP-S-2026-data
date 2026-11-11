#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long c[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long mn=1e12,mx=-1e12;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<mn)mn=a[i];
        if(a[i]>mx)mx=a[i];
    }
    sort(a+1,a+n+1);
    if(mx==mn)cout<<n<<endl;
    else if((mx-mn)*(mx-mn)*n<=1e8){
        long long xcnt=0;
        for(int i=mn;i<=mx;i++){
            //    cout<<"-"<<i<<"-";
            long long m2=m,cnt=0;
            for(int j=i;j>=mn;j--){
                for(int k=1;k<=n;k++){
                    if(a[k]==j){
                        if(m2-(i-j)>0)m2-=(i-j),cnt++;
                        else if(m2-(i-j)==0){
                            m2-=(i-j),cnt++;
                            break;
                        }else break;
                    }
                }
                if(m2==0)break;
            }
            if(cnt>xcnt){
                //cout<<i<<"         ";
                xcnt=cnt;
            }
        }
        cout<<xcnt<<endl;
    }else{
        long long m2=m;
        long long c=a[2]-a[1];
        int cnt=1;
        for(;m>=c*cnt&&cnt<n;){
            m-=c*cnt;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
