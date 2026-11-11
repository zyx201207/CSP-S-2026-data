#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,i,j,s=0;
int a[211111];
char c[211111];
void solve(){
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(i>1&&c[i]==c[i-1]){
            a[i-1]+=a[i];
            i--;
            n--;
        }
    }
    for(i=1,j=n;i<j;){
        if(c[i]!=c[j]){//////////////////
            if(a[i]<a[j]){
                s+=a[i];
                a[j]-=a[i];
                i++;
            }
            else if(a[i]>a[j]){
                s+=a[j];
                a[i]-=a[j];
                j--;
            }
            else{
                s+=a[i];
                i++;
                j--;
            }
            continue;
        }////////////////////////////////
        //c[i]==c[j]
        if(a[i]<a[j]){
            a[j]-=a[i];
            i++;
        }
        else if(a[i]>a[j]){
            a[i]-=a[j];
            j--;
        }
        else{
            i++;
            j--;
        }
    }//for.end
    cout<<s;
}
signed main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
///00:10~01:00 do(T1)&check(T1)
///01:00~01:20 read(T2/3/4)
///01:20~01:50 do(T2)
