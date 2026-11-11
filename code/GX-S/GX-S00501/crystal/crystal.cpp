#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m;
const int N=5e5+7;
int a[N]={};
int s[N]={};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool isspecial=1;   //judge if it features A
    int gc;
    s[1]=0;
    for(int i=1;i<=n;i++){
        if(i>=2) s[i]=s[i-1]+i;
        cin>>a[i];
        if(i==2) gc=a[i]-a[i-1];
        if(i>=2&&a[i]-a[i-1]!=gc){
            isspecial=0;
        }
    }
    sort(a+1,a+n+1);
    if(isspecial){
    for(int i=2;i<=n;i++){
        if(s[i]*gc>m){
            cout<<(i-1);
            return 0;
        }
    }
    }
    for(int i=2;i<=n;i++){
            long long cha=0;
        for(int j=1;j<=i;j++){
            cha+=a[i]-a[j];
            if(cha>m) break;
        }
        if(cha>m){
        cout<<i-1;
        return 0;
        }
    }
}
