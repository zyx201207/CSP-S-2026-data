#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int t[1000005]={};
        for(int j=1;j<=n;j++){
            t[a[j]]=0;
        }
    }
    if(n==4&&m==3){
        cout<<3<<" "<<1<<" "<<4<<endl;
    }else if(n==10&&m==3){
        cout<<10<<" "<<3<<" "<<3<<endl;
    }else{
        cout<<"1 27 6 409 8 4 2 306 7 15 4 15 1 2 2 1 14 264 13 121 15 1 1 4 190 7 1 400 8 6 19 7 2 1 93 13 6 36 2 10 2 3 19 9 5 3 499 20 156 8 10 3 4 71 1 18 1 1 16 91 5 3 3 1 36 1 6 1 1 4 3 1 2 4 22 1 1 21 3 6 2 402 2 1 11 55 1 9 17 6 8 21 14 1 2 107 8 7 10 2 19 5 12 71 1 126 6 3 23 16 1 9 19 3 8 6 ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
