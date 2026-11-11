#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int s1;
    string s2;
}a[200010];
 int n;
int sum;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
        sum+=a[i].s1;
    }
    sum/=2;
    int cnt=0;
    int k=1;
    int l=n;
  //  cout<<sum<<endl;
    while(sum>=a[k].s1){
        if(a[k].s2!=a[l].s2){
     //   cout<<a[k].s2<<a[l].s2<<endl;
       // cout<<k<<"   >v<  "<<l<<endl;
         int c=a[l].s1;
            cnt+=min(a[k].s1,a[l].s1);
            sum-=min(a[k].s1,a[l].s1);
            a[l].s1-=min(a[k].s1,a[l].s1);
            a[k].s1-=min(a[k].s1,c);

            }
        else{
            int c=a[k].s1;
            sum-=min(c,a[l].s1);
            a[k].s1-=min(a[k].s1,a[l].s1);
            a[l].s1-=min(c,a[l].s1);
            }
    //    cout<<a[k].s1<<" "<<a[l].s1<<" "<<sum<<" "<<cnt<<" "<<endl;
      //  cout<<endl;
        if(a[k].s1==0)k++;
        if(a[l].s1==0)l--;
        if(sum==0)break;
    }
    cout<<cnt<<endl;
    return 0;
}


