#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[100005],b[100005];
int maxn = INT_MIN;
vector<int> p;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;

    for(int i = 0;i < n;i ++){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(a,a+n,cmp);
    if(m == n){
        maxn = a[0];
        for(int i = 1;i < n; i++){
            maxn = maxn&a[i];
        }
    }else if(m == 1){
        cout<<a[0];
        return 0;
    }else if(m == 2){
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                p.push_back(b[i]&b[j]);
                maxn = max(maxn,(b[i]&b[j]));
            }
        }
    }else if(m == 3){
        maxn = a[0]&a[1]&a[2];
        cout<<a[0]<<endl<<a[1]<<endl<<a[2]<<endl;
    }
    cout<<maxn<<endl;
    return 0;
}