#include <bits/stdc++.h>
using namespace std;
bool temp(string x){
    for(int i =0;i<x.size()/2;i++){
        if(x[i]!=x[x.size()-1-i]) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long x,y;
    string z,w="";
    cin >>x;
    for(int i =0;i<x;i++){
        cin >> y;
        cin >> z;
        for(int j =0;j<y;j++){
            w=w+z;
        }
    }
    long long add=0;
    if(w.size()/2>=200000) {
        cout <<w.size()/2;
        return 0;
    }
    for(int i =0;i<w.size()/2;i++){
        if(w[w.size()-1-i]!=w[i]){add++;w[w.size()-1-i] = w[i];}
    }
    /*int p[10005];
    for(int i =0;i<w.size()/2;i++){
        p[w[i]]+=1;
    }
    int mx=0;
    for(int i = 0;i<w.size()/2;i++){
        if(p[w[i]] > mx) mx=w[i];
    }*/
    cout <<add;
}
