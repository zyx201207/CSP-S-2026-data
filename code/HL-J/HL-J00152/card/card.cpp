#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn =5e5+10;
const int maxm =3e5+10;
int cnt[maxm],a[maxn];
bool ok=0;
int pos[maxn],n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
   for(int i=1;i<=n;i++){
     cin>>a[i];if(a[i]<a[i-1])ok=0;
   }
 for(int s=1;s<=n;s++){
     for(int i=s;i<=n;i++){
        if(pos[a[i]]){
         for(int i=1;i<=m;i++)pos[a[i]]=0;
        }
        pos[a[i]]=i;
     }
     for(int i=1;i<=n;i++){
         if(pos[a[i]])cnt[a[i]]++;
         pos[a[i]]=0;
     }
 }
 for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}