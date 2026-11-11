#include<bits/stdc++.h>
using namespace std;
struct node{
  long long num;
  char c;
}a[200005];
node d[200005];
long long ans;
int main(){
  freopen("string3.in","r",stdin);
  freopen("string.out","w",stdout);
  int q;cin>>q;
  for(int i=1;i<=q;i++){
    cin>>d[i].num>>d[i].c;
  }
  int n=1;
  a[1]=d[1];
  for(int i=2;i<=q;i++){
     if(d[i].c==a[n].c)a[n].num+=d[i].num;
     else {
        n++;
        a[n]=d[i];
     }
  }
  for(int i=1;i<=(n+1)/2;i++){
     int m=n-i+1;
     if(a[i].c==a[m].c){
            if(a[i].num>a[m].num){
            long long cnt=a[i].num-a[m].num;
            a[m].num=a[i].num;
            if(a[m-1].c!=a[i].c)ans+=cnt;
            a[m-1].num-=cnt;
        }
        else if(a[i].num<a[m].num){
            long long cnt=a[m].num-a[i].num;//chazhi
            a[i].num+=cnt;
            if(a[i+1].c!=a[m].c)ans+=cnt;
            a[i+1].num-=cnt;
        }
    }
    else {
        if(a[i].num==a[m].num)ans+=a[i].num;
        else if(a[i].num>a[m].num){
            long long cnt=a[i].num-a[m].num;
            ans+=a[m].num;
            a[m].num=a[i].num;
            a[m].c=a[i].c;
            if(a[m-1].c!=a[i].c)ans+=cnt;
            a[m-1].num-=cnt;
        }
        else if(a[i].num<a[m].num){
            long long cnt=a[m].num-a[i].num;
            ans+=a[i].num;
            a[i].num=a[m].num;
            a[i].c=a[m].c;
            if(a[i+1].c!=a[m].c)ans+=cnt;
            a[i+1].num-=cnt;
        }
    }
  }
  cout<<ans<<'\n';
  return 0;
}//rp++
