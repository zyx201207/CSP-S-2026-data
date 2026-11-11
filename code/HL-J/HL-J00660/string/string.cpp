#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum1=0,sum2=0,sum3=0,sav=0;
    long long a[200007];
    string S;
    cin >> n;
    for(int i = 1;i<=n;i++){
      cin >> a[i] >> S[i];
      sum1 += a[i];
    }
    for(int i = 1;i<=n;i++){
      sum2 += a[i];
      if(sum2>=sum1/2){
        sav=i;
        sum2-=sum1/2;
        break;
      }
    }
    for(int i =n+1;i>=sav+1;i--){
      a[i]=a[i-1];
      S[i]=S[i-1];
    }
    S[sav]=S[sav+1];
    a[sav]=a[sav+1]-sum2;
    a[sav+1]=a[sav+1]-sum2;
    if(a[sav+1]%2==1){a[sav+1]-=1;}
    int p=1;
    while (p==sav||n==sav+1){
      if(a[p]>=a[n]){
        a[p]-=a[n];
        if(S[p]!=S[n]){sum3+=a[n];}
      }else{
        a[n]-=a[p];
        if(S[p]!=S[n]){sum3+=a[p];}
      }
      if(a[p]==0){p++;}
      if(a[n]==0){n--;}
    }
    cout << sum3;
    return 0;
}
