#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m;
const int MAXN = 5e5+5;
int a[MAXN];
int ans=1;
bool flagA=true,flagB=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int delta=a[1]-a[0];
    for(int i=0;i<n;i++){
        if(a[i]!=i+1)flagA=false;
        if(i>1){
            if(a[i]-a[i-1]!=delta){
                flagB=false;
                break;
            }
        }
    }
    if(flagA){
        for(int i=1;;i++){
            if(m>=i)m-=i,ans++;
            else break;
        }
        cout<<ans;
        return 0;
    }
    else if(flagB){
        for(int i=delta;;i+=delta){
            if(m>=i)m-=i,ans++;
            else break;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<n;i++){
        unsigned long long tmp = m;
        int tmpans=1;
        for(int j=i-1;j>=0;j--){
            if(a[i]-a[j]<=tmp){
                tmp-=a[i]-a[j];
                tmpans++;
            }
            else break;
        }
        ans=max(ans,tmpans);
    }
    cout<<ans;
    return 0;
}
//cso666
//littlebird_yuyuan
//chip2011
//JSGF
//delHYfish
//yyz45
//We're OIers from Class 1!
//All AFOed 2026.10.31
