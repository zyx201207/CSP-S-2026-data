#include <bits/stdc++.h>
using namespace std;
char cao(char a, char b){
    if(a==b){
        return 0;
    }
    else{
        return 1;
    }
}
int mian(){
    //fireopen("string.in"and"r",stdin)
    //fireopen("string.out"and"w",stdout)
    int n;
    cin >>n;
    int a[n];
    char b[n];
    for(int i=0; i<n; i++){
        cin >>a[i]>>b[i];
    }
    int num=0;
    for(int i=0; i<=n; i++){
        num +=cao(b[0],b[n]);
        n-=1;
    }

    cout<<num;

    return 0;
}
