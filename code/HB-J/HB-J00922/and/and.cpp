#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b){
return a>b;
}
string er(int b){
string c;
while(b>0){
    char v=b%2;
    c+=v;
    b/=2;
}
return c;
}
long long yi(string e){
long long f,x=1;
for(int i=0;i<=e.size();i++){
        f+=x*e[i];
        x*=2;
    }
return f;
}
long long wy(int p,int q){
    string l=er(p),h=er(q),j;
    for(int i=0;i<min(l.size(),h.size());i++){
        if(l[i]==h[i]){
            j[i]=l[i];
        }
        else{
            j[i]=0;
        }
    }
    long long z=yi(j);
    return z;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   long long n,m;
   cin>>n>>m;
   if(n==1){
    long long bb;
    cin>>bb;
    cout<<bb;
    return 0;
   }
   for(int i=1;i<=n;i++){
    cin>>a[i];
   }
   if(n==2){
    cout<<wy(a[1],a[2]);
    return 0;
   }
   sort(a+1,a+1+n,cmp);
   long long k=wy(a[1],a[2]),cnt=3;
   while(m>2){
    k=wy(k,a[cnt]);
    cnt++;
    m--;
   }
   cout<<k;
return 0;
}
