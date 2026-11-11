#include <bits/stdc++.h>
using namespace std;
long long n;
const int N=(int) 2*1e5+10;
struct node{
    long long x;
    char y;
};
node a[N];
long long sum;
long long l=1,r;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
      cin>>n;
      r=n;
      for(long long i=1;i<=n;i++){
        long long t1;
        char t2;
        cin>>t1>>t2;
        a[i].x=t1;
        a[i].y=t2;
      }
      while(true){
        if(l>=r){
            break;
        }
        if(a[l].x>a[r].x){
            if(a[l].y==a[r].y){
                a[l].x-=a[r].x;
                r--;
                if(a[l].x==0){
                    l++;
                }
            } else{
                sum+=a[r].x;
                a[l].x-=a[r].x;
                r--;
                if(a[l].x==0){
                    l++;
                }
            }
        } else{
            if(a[r].y==a[l].y){
                a[r].x-=a[l].x;
                l++;
                if(a[r].x==0){
                    r--;
                }
            } else{
                sum+=a[l].x;
                a[r].x-=a[l].x;
                l++;
                if(a[r].x==0){
                    r--;
                }
            }
        }

      }
      cout<<sum;
    return 0;
}
