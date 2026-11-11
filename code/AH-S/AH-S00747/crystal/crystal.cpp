#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
int n;
ll m,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int f=1,ans=-1;
    ll g=0;
    int h=1,t=2,cnt=0;//t-1=now
    while(h!=n){
        cnt++;
        if(cnt>=3*n) break;
        if(g<=m){
            ans=max(ans,f);
            while(1){
                if(t==n+1) break;
                t++;
                f++;
                g+=(t-1-h)*(a[t-1]-a[t-2]);
                //cout<<h<<" "<<t<<" "<<f<<" "<<g<<"\n";
                if(g>m){
                    ans=max(ans,f-1);
                    break;
                }
            }
        }else{
            while(1){
                if(h==t-1) break;
                g-=(a[t-1]-a[h]);
                h++;
                f--;
                //cout<<h<<" "<<t<<" "<<f<<" "<<g<<"\n";
                if(g<=m){
                    break;
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
5 5
1 2 4 8 9
*/
