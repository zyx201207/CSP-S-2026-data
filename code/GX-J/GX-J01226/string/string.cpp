#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[100000];
int sum;
string b[26];
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out", "w",stdout);
     cin>>n;
     for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
     }
     string A=" ";
     for(int j=1;j<=n;j++){
     for(int i=1;i<=a[j];i++){
        A+=b[j];
     }
     }
     for(int i=1;i<=A.length()/2;i++){
        for(int j=n;j>=A.length()/2;j--){
            if(A[i]!=A[j]){
               sum++;
            }
        }
     }
     cout<<sum;
    return 0;
}
