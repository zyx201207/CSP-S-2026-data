#include<bits/stdc++.h>
#define fin cin
#define fout cout
#define ll long long
using namespace std;
ll n,m,c,t,ans,ls;
vector<ll> p;
int main(){
    ifstream fin; ofstream fout;
    fin.open("migrate.in");
    fout.open("migrate.out");
    fin>>c>>t;
    for(int www=0;www<t;www++){
        fin>>n>>m;p={};
        ll k,j=1;ans=0;
        for(int i=1;i<=n;i++){
            fin>>ls;
            p.push_back(ls);
        }for(int i=0;i<n;i++){
            for(int j=i+3;j<n;j++){
                queue<pair<ll,ll>> q;
                q.push({p[i],0});
                int an=0,ns=0;
                while(q.empty()){
                    pair<ll,ll> l=q.front();
                    if(l.first==j&&ns==0){
                        an=l.second;
                        ns++;
                    }else if(ns!=0&&l.first==j&&l.second==an){
                        ns++;
                        if(ns>=3) break;
                    }else if(l.second>an){
                        if(ns==2) ans++;
                        break;
                    }else{
                        for(int k=1;l.first+k<=j&&p[l.first]+m>=p[l.first+k];k++){
                            q.push({l.first+k,l.second+1});
                        }
                    }q.pop();
                }
            }
        }fout<<ans;
    }
    fin.close();fout.close();
    return 0;
}
