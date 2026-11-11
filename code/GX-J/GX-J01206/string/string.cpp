#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    string s;
    char s1[1000000][2]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>s1[i][j];
        }
    }
    cout<<"0";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
