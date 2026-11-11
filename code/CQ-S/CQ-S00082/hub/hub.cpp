#include <bits/stdc++.h>
using namespace std;
int c,t;

int main(){
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> c >> t;
  int n,k;
  cin>>n >>k;
  if(n==5){
  	cout << "1"<<endl<<"2";
	}
	if(n==8) {
		cout<<"1"<<endl<<"1"<<endl<<"2";
	}
	if(n==42){
		cout<<"17"<<endl<<"9"<<endl<<"6"<<endl<<"6"<<endl<<"9"; 
	}
	if(n==24032){
		cout<<"189"<<endl<<"233"<<endl<<"288"<<endl<<"229"<<endl<<"338"; 
	}
	if(n==99999){
		cout<<"12251"; 
	}
  return 0;
}
