#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;
int n,m,t;
int a[N];
/*
int er(int x){
    string s="";
    int s2=0;
    while(x!=0){
        s+=(x%2+'0');
        x/=2;
    }
    for(int i=s.size()-1;i>=0;i--){
        s2=s2*10+(s[i]-'0');
    }
    return s2;
}
*/
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=n-1,j=0;i>=0&&j<m;i--,j++){
        if(i==n-1){
            t=a[i];
        }
        else{
            t=t&a[i];
        }
//        cout<<t<<endl;
    }
    cout<<t;
    return 0;
}
