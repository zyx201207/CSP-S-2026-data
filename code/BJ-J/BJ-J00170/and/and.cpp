#include <bits/stdc++.h>
#include <vector> 
#include <cmath>
using namespace std;
int main(){
    int m,n;
    cin>>n>>m;
    vector<int> li [n];
    vector<int> li2 [n];
    for(int i=0;i<n;i++){
        cin>>li[i];
    }
    int max_n=-12;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(li[j]>=li[j+1]){
                swap(li[j,li[j+1]]);
            }


        }
    }
    int ans=li[m-1];
    cout<<ans;
    return 0;

    //
    // vector<pair<int,int>> li3 [30];
    // for(int k=0;k<n;k++){
    // for(int i=30;i>0;i++){
    //     if(li[k].first&(1>>i)){
    //         li3[i].first+=1;
    //         li3[i].second=li[i];
    //     }
    // }

    // }
    // for(int i=0;i<lis.size();i++){
    //     if(lis[i]>=m){


    //     }

    // }
}