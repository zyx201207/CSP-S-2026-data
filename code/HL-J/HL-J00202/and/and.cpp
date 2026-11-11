#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int mm=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mm=max(mm,a[i]);
    }
    int mn=a[0];
    for(int i=0;i<n;i++){
        mn&=a[i];
    }
    if(m==1){
        cout<<mm;
        return 0;
    }
    if(m==n){
        cout<<mn;
        return 0;
    }
    if(m==2){
        int mg=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                mg=max(mg,a[i]&a[j]);
            }
        }
        cout<<mg;
        return 0;
    }
    sort(a,a+n,greater<int>());
    int ans=-1;
    for(int i=0;i+m<n;i++){
        int s=a[i];
        for(int j=i;j<i+m;j++){
            s&=a[j];
        }
        ans=max(ans,s);
    }
    cout<<ans;
    return 0;
}
