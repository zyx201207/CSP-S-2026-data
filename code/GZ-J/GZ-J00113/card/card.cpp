//GZ-J00113 王铭皓 贵州省贵阳市南明区华麟学校
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> q;
vector <int> win;
bool ch(int a){
    while(!win.empty()){
        if(win[i]==a) return 1;
    }
    return 0;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>q[i];

    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(ch(q[j])){

            }
        }
    }
    return 0;
}
