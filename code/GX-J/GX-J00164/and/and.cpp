#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m,ReTemp;
    cin>>n>>m;
    vector<int> in_list;
    for(int i=0;i<n;i++){
        cin>>in_list[i];
    }
    for(int i=0;i<n;i++){
        int and_temp;
        and_temp=in_list[i];
        for(int s=1;s<m;s++){
            and_temp=and_temp&in_list[i+s];
        }
        ReTemp=max(ReTemp,and_temp);
    }
    cout<<ReTemp;
    return 0;
}
