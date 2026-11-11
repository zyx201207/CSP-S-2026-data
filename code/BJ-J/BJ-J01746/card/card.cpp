#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v;
vector<int>annswer;
int b[20000005];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++){
        annswer.push_back(v[i]);
            
        for(int j=0;j<n;j++){
            if(v[i]==annswer[j]){
                for(int k=j;k<n;k++){
                    annswer[k]=0;
                }
                 annswer.push_back(v[i]);
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=0;j<n;j++){
                if(annswer[j]==i)b[i]++;
            }
        }
        
    }
    
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
        }
    return 0;
}