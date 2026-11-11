#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  bool f=1;
  string c1=0,c2=0,s1=0,s2=0;
  cin>>c1>>c2>>s1>>s2;
  if(c1[0]==s1[0]&&c1[1]==s1[1]){
    cout<<"1";
  }else{
    cout<<"0";
    f=0;
  }
  if(c2[0]==s2[0]&&c2[1]==s2[1]&&f){
    cout<<"1";
  }else{
    cout<<"0";
    f=0;
  }
  if(((c2[2]<'D'&&s2[2]<'D')||(c2[2]>'C'&&s2[2]>'C'))&&f){
    cout<<"1";
  }else{
    cout<<"0";
    f=0;
  }
  if((c2[2]-s2[2]==1||c2[2]-s2[2]==1)&&f){
    cout<<"1";
  }else{
    cout<<"0";
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}