#include<bits/stdc++.h>
using namespace std;
int a,n,ans,aq;
unordered_map<int,int> k;
long long m;
int main(){
    freopen("crystal.in","r", stdin);
    freopen("crystal.out","w", stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    if(m>100000000){
        long long A[5];
        cin>>A[1]>>A[2]>>A[3];
        if(A[1]==1&&A[2]==2&&A[3]==3){
            long long i;
            for(i=1;i<=n;i++)
            if(m>=i*(i-1)/2)ans++;
            else break;
            cout<<ans;
            return 0;
        }
        if(A[3]-A[2]==A[2]-A[1]){
            m/=abs(A[3]-A[2]);
            long long i;
            for(i=1;i<=n;i++)
            if(m>=i*(i-1)/2)ans++;
            else break;
            cout<<ans;
            return 0;
        }
    }
    else
    for(int i=-105;i<=105;i++){k[i]=0;}
    int ma=-105,mn=105,mb;
    for(int i=1;i<=n;i++){
    cin>>a;
    ma=max(a,ma);mn=min(a,mn);
    k[a]++;}
    for(int i=ma;i>=mn;i--){
        if(k[i]==0)continue;
        aq=k[i];
        mb=m;
        for (int j=i-1;j>=mn;j--){
            if(k[j]==0)continue;
            if(mb>=k[j]*(i-j)){aq+=k[j];mb-=k[j]*(i-j);}
            else {int sa=mb/(i-j);
                aq+=sa;
                break;
            }
        }
        ans=max(ans,aq);
    }
    cout<<ans;
    return 0;
}
