#ifndef CARD_CPP_INCLUDED
#define CARD_CPP_INCLUDED
#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int n,m;
int fi(int num){
    for(int j=0;j<v.size();j++){
        if(v[j]==num){
            return j;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector <int> a;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    int times_[m+1]={0};
    while(!a.empty()){
        bool if_c[m+1]={0};
        for(int i=0;i<a.size();i++){
            if(if_c[a[i]]){
                int temp=fi(a[i]);
                v.erase(v.begin()+temp-1,v.end());
                v.push_back(a[i]);
            }else{
                v.push_back(a[i]);
                if_c[a[i]]=1;
            }
        }
        for(int i=0;i<v.size();i++){
                times_[v[i]]++;
            }
        a.erase(a.begin());
        v.erase(v.begin(),v.end());
    }
    for(int i=1;i<=m;i++){
        cout<<times_[i]<<' ';
    }
    return 0;
}

#endif // CARD_CPP_INCLUDED
