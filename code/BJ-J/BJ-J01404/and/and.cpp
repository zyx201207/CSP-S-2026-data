#include<bits/stdc++.h>
#define LL long long
#define endl '\n'
#define pb push_back
using namespace std;
const LL N=2e5+10,M=30+10;
int n,m,x,res=0,a[N][M],tj[M],ans[M];
void zej(int x,int d){
    vector<int>v;
    while(x!=0){
        v.pb(x%2);
        x/=2;
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<(int)v.size();i++){
        a[d][30-(int)v.size()+i+1]=v[i];
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        zej(x,i);
    }
    for(int i=1;i<=30;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=a[j][i];
        }
        tj[i]=sum;
    }
    bool f=0;
    for(int i=1;i<=30;i++){
        int cnt=0;
        if(tj[i]>=m){
            for(int j=1;j<=n;j++){
                if(a[j][i]==1){
                    for(int k=i;k<=30;k++){
                        if(a[j][k]==1)ans[k]++;
                    }
                    cnt++;
                }
                if(cnt==m){
                    f=1;break;
                }
            }
        }
        if(f)break;
    }
    int num=pow(2,29);
    for(int i=1;i<=30;i++){
        if(ans[i]>=m)res+=num;
        num/=2;
    }
    cout<<res<<endl;
    return 0;
}
