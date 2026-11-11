#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
struct se{
    char x;
    int k;
}a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int sum=0;
    bool f=1;
    string s="";
    for(int i=1;i<=n;i++){
        cin>>a[i].k>>a[i].x;
        for(int o=1;o<=a[i].k;o++){
            s+=a[i].x;
        }
        if(i>1&&a[i].x!=a[i-1].x){
            f=0;
        }
    }
    if(f){
        cout<<0;
        return 0;
    }
    int len=s.size();
    if(len%2==0){
        int cnt=0;
        int l=len/2-1,r=len/2;
        while(l>=0&&r<=len-1){
            if(s[l]!=s[r])cnt++;
            l--;r++;
        }
        cout<<cnt;
    }else{
        int cnt=0;
        int l=len/2-1,r=len/2+1;
        while(l>=0&&r<=len-1){
            if(s[l]!=s[r])cnt++;
            l--;r++;
        }
        cout<<cnt;
    }
    return 0;
}
