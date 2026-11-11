#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct AAA{
  long long data;
  char ch;
}a[N];
int n;
unsigned long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].data>>a[i].ch;
    }
    long long l=1,r=n;
    while(l<r){
        if(a[l].ch==a[r].ch){
             //   cout<<"BBBBB";
            if(a[r].data>a[l].data)a[r].data-=a[l].data,l++;
            else if(a[r].data<a[l].data)a[l].data-=a[r].data,r--;
            else l++,r--;
            continue;
        }
        if(a[r].data>a[l].data){
             //   cout<<"AAAA";
            a[r].data-=a[l].data;
            ans+=a[l].data;
            l++;

        }
        else if(a[r].data==a[l].data)l++,r--,ans+=a[l-1].data;
        else{
             a[l].data-=a[r].data;
            ans+=a[r].data;
            r--;

        }
    }
    cout<<ans;

    return 0;
}
