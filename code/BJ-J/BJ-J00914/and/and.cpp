#include <iostream>
#include <cstring>
using namesapce std;
freopen("and.in","r",std.in)
freopen("and.out","w",std.out)
int main()
{
  int a[10000000];
  int b,c,d;
  for(int i=1;i<=b;i++){
      cin >> a[i];
  }
  if(c=2){
  for(int i=1;i<=b;i++){
      for(int j=1;j<=b;j++){
          if(a[i]!=a[j]&&a[i]&a[j]>d)
          d=a[i]&a[j];
      }
  }
  }
  if(c=3){
  for(int i=1;i<=b;i++){
      for(int j=1;j<=b;j++){
          for(int k=1;k<=b;k++){
          if(a[i]!=a[j]!=a[k]&&a[i]&a[j]&a[k]>d)
          d=a[i]&a[j]&a[k];
    }
  }
  }
}
if(c=4){
for(int i=1;i<=b;i++){
      for(int j=1;j<=b;j++){
          for(int k=1;k<=b;k++){
          for(int x=1;x<=b;x++){
          if(a[i]!=a[j]!=a[k]!a[x]&&a[i]&a[j]&a[k]&a[x]>d)
          d=a[i]&a[j]&a[k]&a[x];
          }
    }
  }
  }
}
cout << d << endl;
  return 0;
}