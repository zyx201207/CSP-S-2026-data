#include <bits/stdc++.h>

using namespace std;

int a[10086];int b[10086];
int n, m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int maxe = 1e6,mine = -1e6;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxe = max(maxe,a[i]);
        mine = min(mine,a[i]);
    }
    for(int i=0;i<n;i++){
        int lomin = -10086;
        for(int j=0;j<n;j++){
            if(lomin>=a[j])lomin = a[j];
        }
        b[i] = lomin;
    }
    int cen = b[n/2];
    int maxn = -10086;
    for(int i=n-1;i>=0;i--){
        int pu = m;
        int maxe = 0;
        for(int j=i-1;j>=0;j--){
            if(a[i] - a[j] <= pu){
                pu = pu - (a[i]-a[j]);
                maxe++;
            }
            else break;
        }
        if(maxe > maxn){maxn = maxe;}
    }
    cout<<maxn+1;
}
