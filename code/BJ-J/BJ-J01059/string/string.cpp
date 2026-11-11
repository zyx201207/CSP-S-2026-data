#include <bits/stdc++.h>
using namespace std;
const int N=2e6+6;
#define int long long

struct node{
    int x;
    string y;
}ve[N];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>ve[i].x>>ve[i].y;
    }
    int i=0,j=n-1;
    int sum=0;
    while (i<j){
        bool f=0;
        if(ve[i].y!=ve[j].y) f=1;
        if (ve[i].x<ve[j].x){
            if(f) sum+=ve[i].x;
            ve[j].x-=ve[i].x;
            i++;
        }else if (ve[i].x>ve[j].x){
            if(f) sum+=ve[j].x;
            ve[i].x-=ve[j].x;
            j--;
        }else if (ve[i].x==ve[j].x){
            if(f) sum+=ve[i].x;
            i++;j--;
        }
    }
    cout<<sum;
}
