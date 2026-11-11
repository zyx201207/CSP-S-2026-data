#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","W",stdout);
    int a,num;
    cin>>a;
    int n[a];
    char m[a];
    for(int i=0;i<a;i++){
        cin>>n[i];
        cin>>m[i];
        num+=n[i];
    }
    int nm=num/2;
    int cmp=num-nm;
    cout<<cmp;
return 0;
}
