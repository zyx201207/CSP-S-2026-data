#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m,I=0;
int p[1000000]={0},ans[1000000]={0};
int play(int a){
    vector<int> b;
    int ant=1;
    b.push_back(p[a]);
    for(int i=a+1;i<n;i++){
        int delet=0;
        for(int j=0;j<ant;j++){
            if(b[j] == p[i]) delet = ant-j;//是否重复
        }
        for(int j=0;j<delet;j++){
            b.pop_back();
            ant--;
        }
        b.push_back(p[i]);
        ant++;
    }
    for(int i=0;i<ant;i++){
        ans[b[i]]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.ont","w",stdont);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        play(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}