#include<bits/stdc++.h>
using namespace std;
bool a1=0,a2=0,a3=0,a4=0;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  string a,b,c,d;
  cin>>a>>b>>c>>d;
  if(a==c){
        cout<<1;
        a1=1;
  }
  else cout<<0;
  string id1,id2;
  char AA1,AA2;
  for(int i=0;i<3;i++){
    if(i<2){
        id1+=b[i];
        id2+=d[i];
    }
    else{
        AA1=b[i];
        AA2=d[i];
    }
  }
  if(AA1>AA2)swap(AA1,AA2);
  if(id1==id2&&a==c&&a1==1){
        cout<<1;
        a2=1;
  }
  else cout<<0;
  if(id1==id2&&(((AA1=='A'||AA1=='B'||AA1=='C')&&(AA2=='A'||AA2=='B'||AA2=='C'))||(AA1=='D'||AA2=='F')&&a==c)&&a2==1){
        cout<<1;
        a3=1;
  }
  else cout<<0;
  if(id1==id2&&(abs(int(AA1-AA2))==1||(AA1=='D'&&AA2=='F')&&(AA1!='C'&&AA2!='D')&&a==c)&&a3==1)cout<<1;
  else cout<<0;
  return 0;
}
