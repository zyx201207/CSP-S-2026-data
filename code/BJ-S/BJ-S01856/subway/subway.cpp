#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    ll w[50005];
    vector<int> a[505],t[505];
    map<int,ll> ln[505];
    vector<int> st[50005];
    int k,ta,tt;
    for(int i=0;i<m;i++){
        scanf("%d ",&tt);
        w[i]=tt;
    }
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            scanf("%d %d ",&ta,&tt);
            a[i].push_back(ta);
            t[i].push_back(tt);
            st[ta].push_back(i);
            ln[i][ta]=tt;
        }
    }
///////////////////////////////
    ll l[505][505]={0};
    for(int i=0;i<505;i++) for(int j=0;j<505;j++) l[i][j]=999999999999;
    for(int i=0;i<n;i++){//line:i
        int s=a[i].size();
        for(int j=0;j<s;j++){//station:a[i][j]
            ll tp=a[i][j];
            int s2=st[a[i][j]].size();
            for(int p=0;p<s2;p++){//change:st[a[i][j]][p]
                ll tp2=st[tp][p];
                l[i][tp2]=min(l[i][tp2], (ln[i][tp] + ln[tp2][tp]) );
            }
        }
    }
    for(ll p=0;p<n;p++){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(l[i][p]+l[p][j]<l[i][j]){
                    l[i][j]=l[i][p]+l[p][j];
                }
            }
        }
    }
//////////////////////
    for(int qwerty=0;qwerty<q;qwerty++){
        ll s,e,mn=99999999999;
        cin>>s>>e;
        for(int i=0;i<st[s].size();i++){
            for(int j=0;j<st[e].size();j++){
                mn=min(mn,l[st[s][i]][st[e][j]]);
            }
        }
        printf("%lld\n",w[s]+w[e]+mn);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
