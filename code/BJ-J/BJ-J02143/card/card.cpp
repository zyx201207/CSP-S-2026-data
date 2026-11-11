#include <bits/stdc++.h>

using namespace std;

int car[500005];
int num[500005]={0};
int a[500005]={0};
bool c_a(int x,int y){
    for(int i=0;i<x;i++){
        if(a[i]==y){
            return true;
        }
    }
    return false;
}
int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> car[i];
    }
    stack<long long>v;
    while(!v.empty()){
        v.pop();
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(c_a(i,car[j])==false) {
                    v.push(car[j]);
                    a[v.size()]=car[j];
            }
            else{
                int cha=1;
                while(cha==1){
                    if(v.top()!=car[j]){
                        v.pop();
                    }
                    else{
                        v.pop();
                        a[v.size()]=0;
                        cha--;
                    }
                }
            }
        }
        while(!v.empty()){
            num[v.top()]++;
            v.pop();
        }
    }
    for(int i=0;i<m;i++){
        cout << num[i] << " ";
    }
    return 0;
}
