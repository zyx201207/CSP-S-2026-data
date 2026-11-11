#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[200009];
int m[100009];
int mm[200009];
int st[200009];
int s[100009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,tm;
    cin>>n>>tm;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--){
        if(m[a[i]]==0) mm[i]=-1;
        else mm[i]=m[a[i]];
        m[a[i]]=i;
    }
    int t=0;
    for(int i=0;i<n;i++){
        t++;
        if(mm[i]!=-1){
            st[mm[i]]+=st[i]+1;
            t--;
        }else{
            t+=st[i];
			s[a[i]]+=t;
        }
    }
    for(int i=1;i<=tm;i++){
        cout<<s[i]<<' ';
    }
    return 0;
}
