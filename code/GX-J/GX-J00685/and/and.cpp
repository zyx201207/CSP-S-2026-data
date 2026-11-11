#include <bits/stdc++.h>
using namespace std;
long long arr[2000005]={0};
long long arr2[2000005]={0};
int main(){
freopen ("and.in","r,"stdin);
freopen("and.out","w",stdout);
int m,n;
cin>>m>>n;
for(int i=0,i<n;i++){
   cin>>arr[i];
     }
     for(int i=0 i<m,i++){
        arr2[i]=arr[i]%2;
     }
     cout<<max(arr[1],arr[100]+arr[1]);
return 0;
}
