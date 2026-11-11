#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  vector<char>c;
  vector<int>x;
  for(int i=0;i<2;i++){
      cin>>c[i];
      cin>>x[i];
  }
  if(c[0]==c[1])cout<<1;
  else cout<<0;
  return 0;
}
