#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000005],cnt;
bool two_way(int l,int r){
    long long c[r-l+1];memset(c,1,sizeof(c));
    c[0]=1;int cnt2=0;
    for(int i=0;i<=r-l;i++){
        for(int j=i-1;j>=0;j--){
            if(a[i]-a[j]<=d){
                if(i==r-l){
                    if(c[j]+1<c[i]){cnt2=1;c[i]=c[j]+1;}
                    else cnt2++;
                }
                else c[i]=min(c[j]+1,c[i]);
            }
        }
    }
    return cnt2==2;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;long long ans=0;
        for(int i=1;i<=n;i++){cin>>a[i];}
        if(c<=10){
            for(int l=1;l<=n;l++){
                for(int r=l+1;r<=n;r++){
                    if(a[r]-a[l]<=d)continue;
                    if(two_way(l,r))ans++;
                }
            }
        }else if(c==11||c==12){
            if(a[2]-a[1]>=d)ans=0;
            else ans=n-2;
        }else if(c==13||c==14){
            for(int l=1;l<=n;l++){
                for(int r=l+1;r<=n;r++){
                    int cnt3=0;
                    for(int k=l;k<=r;k++){
                        if(a[k]-a[l]<=d&&a[r]-a[l]<=d){
                            cnt3++;if(cnt3>2)break;
                        }
                    }
                    if(cnt3==2)ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
