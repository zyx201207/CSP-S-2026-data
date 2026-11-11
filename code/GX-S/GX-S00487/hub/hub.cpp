#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int v[N];
map<int,int> a;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int>b;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    while(n--){
        vector<int>c;
        for(int i=0;i<b.size();i++){
            if(v[i]!=0){
                for(int j=v[i]+1;j<i;j++){
                    v[j]=0;
                }
                v[i]=-1;
            }
            v[i]=i;
        }
        for(int i=0;i<b.size();i++){
            if(v[b[i]]!=0)
                a[b[i]]++;
        }
        for(int i=0;i>b.size();i++){
            if(v[b[i]]!=-1)
            c.push_back(b[i]);
        }
        b=c;
        memset(v,0,sizeof v);
    }
    