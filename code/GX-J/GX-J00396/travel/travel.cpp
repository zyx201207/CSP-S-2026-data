#include<bits/stdc++.h>
using namespace std;
int t[1001];
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  int q=0,w=0,e=0,g=0;
  string a,b,x,y;
  cin>>a>>x>>b>>y;
  //cout<<a<<" "<<x<<" "<<b<<" "<<y<<endl;
  q='A'+'B';
  w='B'+'C';
  e='D'+'F';
  for(int i=0;i<5;++i)
    t[i]=g;
  //cout<<q<<" "<<w<<" "<<e<<" "<<endl;
  if(x[2]+y[2]==q || x[2]+y[2]==w) t[2]=1,t[3]=1;
  else if(x[2]+y[2]==e) t[2]=1,t[3]=1;
       else if(x[2]<'D' && y[2]<'D') t[2]=1,t[3]=0;
            else if(x[2]>'C' && y[2]>'C') t[2]=1,t[3]=0;
                 else t[2]=0,t[3]=0;
  if(x[0]==y[0] && x[1]==y[1]) t[1]=1;
  else t[1]=0,t[2]=0,t[3]=0;
  if(a[1]==b[1]) t[0]=1;
  else t[0]=0,t[1]=0,t[2]=0,t[3]=0;
  for(int i=0;i<4;++i)
    cout<<t[i];
  return 0;
}
