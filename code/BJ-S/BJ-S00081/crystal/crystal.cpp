#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500020],b[500020];
int main(){
//    int rp=0;
//    rp++;
//    rp=2147483647;
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ll n,ans=0,t=0,m=0,m1=0,i1=0,cnt=0;
    cin>>n>>m;

 //   cout<<"n:"<<n<<" m:"<<m<<endl<<"a[i]:";
    for(int i=1;i<=n;i++){
        cin>>a[i];
  //      cout<<a[i]<<" ";
    }

    sort(a+1,a+n+1);

 //   cout<<endl<<"b[i]:";
    for(int i=1;i<=n;i++){
        b[i]=a[i+1]-a[i];
 //       cout<<b[i]<<" ";
    }
 //   cout<<endl;


    for(int i=1;i<=n;i++){
        t=1;
        m1=m;
        i1=i;
        cnt=0;
        while(1){
            //cout<<"//b[i1]="<<b[i1]<<endl;
            if(b[i1]<0)break;
            cnt++;
            m1-=b[i1]*cnt;
            if(m1<0)break;
            if(i1>n)break;
            t++;
            i1++;
        }
        //cout<<"//"<<a[i]<<"->"<<a[i+t-1]<<" , t="<<t<<" , m1="<<m1<<endl;

        ans=max(ans,t);
    }

    cout<<ans;
    return 0;
}
