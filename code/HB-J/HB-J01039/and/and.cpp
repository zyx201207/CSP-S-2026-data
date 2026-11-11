#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int n,m,ans=0;
vector<int> a,b;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int x;
    int maxnum,sumans;
    cin>>x;
    maxnum=x;
    sumans=x;
    a.push_back(x);
    for(int i=1;i<n;i++){
        cin>>x;
        sumans=sumans&x;
        maxnum=max(maxnum,x);
        a.push_back(x);
    }
    if(m==1){
        cout<<maxnum;
        return 0;
    }
    if(m==2){
        int l=a.size();
        sort(a.begin(),a.end(),cmp);
        for(int i=0;i<min(32,l);i++){
            for(int j=i+1;j<min(32,l);j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        cout<<sumans;
        return 0;
    }
    ans=n-1;
    int num=n-1;
    for(int i=0;i<m;i++){
        ans=ans&num;
        num--;
    }
    cout<<ans;
    return 0;
}

