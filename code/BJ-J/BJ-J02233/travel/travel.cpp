#include <bits/stdc++.h>
using namespace std;
int main(){
  freopen("travel.in",'r',"cin");
  freopen("travel.out",'w',"cout");
  string a,b,c,d;
  cin >>a>>b>>c>>d;
  if (a[0]==c[0]&&a[1]==c[1]){
    cout <<1<<" ";
    if (b[0]==d[0]&&b[1]==d[1]){
      cout <<1<<" ";
      char n=b[2],m=d[2];
      if (n<='C'&&m<='C'){
	cout <<1<<" ";
	if (n=='B'||m=='B'){
	  cout <<1;
	}else{
	  cout <<0;
	}
      }else if(n>'C'&&m>'C'){
	cout <<1<<" "<<1;
      }else{
	cout <<0<<" "<<0;
      }
    }else{
      cout <<0<<" "<<0<<" "<<0;
    }
  }else{
    cout <<0<<" "<<0<<" "<<0<<" "<<0;
  }
  return 0;
}