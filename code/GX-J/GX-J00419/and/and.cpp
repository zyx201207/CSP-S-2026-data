#include<bits/stdc++.h>
using namespace std;
int n[200000];
int m[200000];
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int a,b;
cin>>a>>b;
for(int i=1;i<=a;i++){
    cin>>n[i];
}
int maxn=0;
int cnt=1;
for(int i=1;i<=a;i++){
for(int j=1;j<=a;j++){
  m[cnt]=n[i]&n[i+1];
  cnt++;
}
}
for(int i=1;i<=a*a;i++){
        maxn=max(maxn,m[i]);

}

    cout<<maxn;



return 0;
}
