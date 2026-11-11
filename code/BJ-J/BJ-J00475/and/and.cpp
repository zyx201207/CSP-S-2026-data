#include <bits/stdc++.h>
using namespace std;
int main(){

freopen("and.in","r",stdin);
freopen("and.out","w",stdout);

int m,n,f = 0,h[100005];
cin>>n>>m;
string a;
int g = 0;
int b[100005] = {};
int c;
for(int i = 0;i<n;i++){
    cin>>b[i];
}
for(int i = 0;i<n;i++){
    if(b[i]!=0){
        c = b[i]%2;
        b[i] = b[i]/2;
    }
    b[i] = c;
    c = 0;
}
for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
        if(a[i]%10 == b[j]%10==1){
            f =f*10+1;
        }
        else{
            f = f*10;
        }
        h[g] = f;
        g++;
        f = 0;
    }
}
for(int i = 0;i<g-1;i++){
    if(h[i]>h[i+1]){
        h[i] = h[i+1];
        h[i+1] = h[i];
    }
}
int u = h[0];
while(h[0]!=0){
    int i = 0;
    if(h[i]%10 == 0){
        continue;
    }
    else if(h[i]%10 == 1){
        int s = i;
        if(s>0){
            u = u+u*2;
        }
        else if(s==0){
            u = u+1;
        }
    }
}
cout<<u;

return 0;
}
