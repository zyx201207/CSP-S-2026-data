#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a[500005],z,sum=1,maxn=-2147483647,ma;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        ma=m;
        sum=1;
        for(int j=i+1;j<n;j++){
            z=a[i]-a[j];
            //cout << z << "\n";
            if(ma>=z){
                ma-=z;
                sum++;
                //cout << sum << "\n";
            }else{
                break;
            }
        }
        //cout << "\n";
        if(sum>maxn){
            maxn=sum;
        }
    }
    cout << maxn;
}
