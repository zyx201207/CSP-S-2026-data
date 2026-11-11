#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> card;
    int a[n],b[m]={},tnt[m]={};
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=0;k<m;k++){
                if(a[j]==k){
                    b[k]++;
                    if(b[k]>=2){
                        for(int f=card[j];f<card.size()-1;f++){
                            card.pop_back();
                        b[k]=0;
                        }
                    }
                }
            }
            card.push_back(a[j]);
        }
        for(int j=0;j<m;j++){
            if(b[j]==1)
                tnt[j]++;
        }
    }
    for(int i=0;i<m;i++)
        cout<<tnt[i]<<" ";
    return 0;
}
