#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","n",stdin);
    freopen("string.out","z",stdout);
    string hw;
    int n;
    cin>>n;
    int s=0;
    for(int i=0;i<n;i++){
        int m=0;
        cin>>m;
        string q;
        cin>>q;
        for(int j=0;j<m;j++){
            hw[s]== q[0];
            s++;
        }
    }
    int d=s;
    int z=0;
    string wh;
    for(int i=0;i<=s;i++){
        wh[i]=hw[s];
        s--;
    }
    if(hw == wh){
        cout << 0;}
    else{
        for (int i=0;i<d;i++){
            if(hw[i]==wh[i]){
                z+=0;
            }
            else{
                z++;}
        }
        cout<< z;
    }


    return 0;
}
