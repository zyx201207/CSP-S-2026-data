#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a1(n);
    vector<int>a(n);
    vector<int>ac;
    vector<int>res;
    bool h[m];
    int cnt[m];
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    stack<int>kards;//wu2,..??!!#%^di2??
    for(int i=0;i<n;i++){

        a=a1;
        while(!a.size()==0){
            for(int j=0;j<i;j++){
                if(h[a[j]]){while(kards.top()!=a[j])kards.pop();kards.pop();h[a[j]]=0;}
                kards.push(a[j]);
                h[a[j]]=1;
            }ac.clear();
            for(int j=i;j<n;j++)ac.push_back(a[j]);
            if(a==ac)break;
            a=ac;
        }

        while(!kards.empty()){
            res.push_back(kards.top());
            kards.pop();
        }
    }
    for(int i=0;i<res.size();i++){
        cnt[res[i]-1]++;
    }
    for(int i=0;i<m;i++)cout<<cnt<<' ';
    return 0;
}
/*
        ________     ________
       / ______/    /_____  /
      / /                / /
     / /______          / /
    /  ____  /         / /
   / /    / /         / /
  / /____/ /         / /
 /________/         /_/
         ________     ________
       / ______/    /_____  /
      / /                / /
     / /______          / /
    /  ____  /         / /
   / /    / /         / /
  / /____/ /         / /
 /________/         /_/
         ________     ________
       / ______/    /_____  /
      / /                / /
     / /______          / /
    /  ____  /         / /
   / /    / /         / /
  / /____/ /         / /
 /________/         /_/
         ________     ________
       / ______/    /_____  /
      / /                / /
     / /______          / /
    /  ____  /         / /
   / /    / /         / /
  / /____/ /         / /
 /________/         /_/
*/
