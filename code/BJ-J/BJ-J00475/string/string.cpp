#include <bits/stdc++.h>
using namespace std;
char b[1000000001] = {};
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int a;
    int c,e = 0,num=0;
    char d;
    cin>>a;
    for(int i = 0;i<a;i++){
        cin>>c;
        cin>>d;
        for(int j = 0;j<c;j++){
            b[e] = d;
            e++;
        }
        continue;
    }
    for(int i = 0;i<e/2;i++){
        for(int j = e-1;j>e/2;j--){
            if(b[i] != b[j]){
                num ++;
            }
        }
    }
    cout<<num;

    return 0;
    }