#include<bits/stdc++.h>
using namespace std;
const int N=10000001;
int n,m;
int a[N];
int main(){
     freopen("card.in","r",stdin);
     freopen("card.out","w",stdout);
     ios::sync_with_stdio();
     cin>>n>>m;
     for(int i=0;i<n;i++){
     cin>>a[i];
     t[a[i]]++;
     }
     for(int i=0;i<1000010;i++){
        if(t[i]>0){
        cout<<t[i];
        }
     }
     return 0;
}
//Trick||Treat!
