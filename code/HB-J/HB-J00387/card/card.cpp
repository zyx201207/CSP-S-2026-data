#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    map<int,int> a;
    vector<int> a1(n);
    int k=0;
    for(int i=0;i<n;i++)cin>>a1[i];
    for(int i1=0;i1<n;i1++){
        vector<int> l,r;
        for(int i=k;i<n;i++){
            int k1=-1;
            a[a1[i]]++;
            for(int j=k;j<i;j++){
                for(int j1=0;j1<l.size();j1++)if(j==l[j1])j=r[j1]+1;
                if(a1[i]==a1[j]){
                    l.push_back(j);
                    r.push_back(i-1);
                    k1=j;break;
                }
            }
            if(k1!=-1){
                for(int j=k1;j<i;j++){
                    a[a1[j]]--;
                }
            }
        }
        k++;
    }
    for(auto i=1;i<=m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
