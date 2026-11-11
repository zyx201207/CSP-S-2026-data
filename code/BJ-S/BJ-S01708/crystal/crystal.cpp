#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[100005],b[100005];
int minf= 999999,t = 0,maxf =-999999;
int main(){
    sizeof(b,b+100005,0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
    cin >> a[i];
    }
    for(int j = 1;j <= m;j++){
    for(int i = 0;i < n;i++){
    if(minf >=a[i]){
    minf= a[i];
    t = i;
    }
    }
    minf = 999999;
    a[t]++;
    }
    for(int i = 0;i < n;i++){
    b[a[i]]++;
    }
    for(int i = 0;i < n;i++){
        if(maxf < b[i])
            maxf = b[i];
    }
cout << maxf;
return 0;
}