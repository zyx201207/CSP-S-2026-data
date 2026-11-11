#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct a{
    ll num;
    char c;
}a[200002];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,cnt=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i].num;
        cin>>a[i].c;
    }
    ll j=n;
    ll maxnum=n-1,minnum=0;
    while(j>0&&maxnum!=minnum){
        if(a[maxnum].c!=a[minnum].c){
            if(a[maxnum].num>a[minnum].num){
                a[maxnum].num-=a[minnum].num;
                cnt+=a[minnum].num;
                minnum++;
                j--;
            }
            else if(a[maxnum].num<a[minnum].num){
                a[minnum].num-=a[maxnum].num;
                cnt+=a[maxnum].num;
                maxnum--;
                j--;
            }
            else if(a[maxnum].num==a[minnum].num){
                cnt+=a[maxnum].num;
                maxnum--;
                minnum++;
                j-=2;
            }
        }
        else if(a[maxnum].c==a[minnum].c){
            if(a[maxnum].num>a[minnum].num){
                a[maxnum].num-=a[minnum].num;
                minnum++;
                j--;
            }
            else if(a[maxnum].num<a[minnum].num){
                a[minnum].num-=a[maxnum].num;
                maxnum--;
                j--;
            }
            else if(a[maxnum].num==a[minnum].num){
                maxnum--;
                minnum++;
                j-=2;
            }
        }
    }
    cout<<cnt;
}