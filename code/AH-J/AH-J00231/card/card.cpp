#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+5;
int a[N]={};
int sta[N]={};
int t[N]={};
int t1[N]={};
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    bool fla=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t1[a[i]]++;
        if(t1[a[i]]>1) fla=0;
    }
    if(fla){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                t[a[j]]++;
            }
        }
        for(int i=1;i<=m;i++) cout<<t[i]<<' ';
        cout<<'\n';
    }
    for(int k=1;k<=n;k++){
        map<int,int> m;
        int top=0;
        for(int st=k;st<=n;st++){
            if(m[a[st]]!=0){
                while(top>0 && a[sta[top]]!=a[st]){
                    m[sta[top]]=0;
                    top--;
                }
                if(top>0){
                    m[sta[top]]=0;
                    top--;
                }
            }
            m[a[st]]=st;
            top++;
            sta[top]=st;
        }
        while(top>0){
            t[a[sta[top]]]++;
            top--;
        }
    }
    for(int i=1;i<=m;i++) cout<<t[i]<<' ';
    cout<<'\n';
    return 0;
}
