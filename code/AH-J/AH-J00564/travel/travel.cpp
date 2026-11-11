#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    if(n==m){
        cout << 1;
    }else{
        cout << 0;
    }
    for(x=1;x<=y;x++){
        cout << 0;
    }
    for(y=1;y<=x;x++){
        cout << 0;
    }
//fclose(stdin);
//fclose(stdout);
return 0;
}
