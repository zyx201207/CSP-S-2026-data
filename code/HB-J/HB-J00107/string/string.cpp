#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+5;

int n,l,r,m;
int a[N];char c[N];
map<char,vector<int>> L;
map<char,vector<int>> R;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        m+=a[i];
    }
    int mid=(m+1)/2,ans=m/2;l=0,r=0;
    for(int i=1;i<=n;i++){
        l=r+1,r+=a[i];
        if(r<=mid){
            L[c[i]].push_back(l);
            R[c[i]].push_back(r);
        } 
        else{
            if(l<=mid&&r>mid){
                L[c[i]].push_back(l);
                R[c[i]].push_back(mid);
                l=mid+1;
            } 
            l-=mid,r-=mid;
            int tl=upper_bound(L[c[i]].begin(),L[c[i]].end(),mid-r)-L[c[i]].begin()-1;
            int tr=lower_bound(R[c[i]].begin(),R[c[i]].end(),mid-l)-R[c[i]].begin();
            if(tl<=tr&&tl>=0&&tl<L[c[i]].size()&&tr>=0&&tr<R[c[i]].size())
                for(int j=tl;j<=tr;j++) ans-=R[c[i]][j]-L[c[i]][j]+1;
        }
    }
    cout<<ans;
}