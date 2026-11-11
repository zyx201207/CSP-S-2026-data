#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	string e,b,c,d;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> e >> b >> c >> d;
	if(e==c){
		a[1]=1;
	}
	else{
		for(int i=1;i<=4;i++){
			a[i]=0;
		}
		for(int i=1;i<=4;i++){
			cout << a[i];
		}
		return 0;
	}
	if(b.substr(0,2)==d.substr(0,2)){
		a[2]=1;
	}
	else{
		for(int i=2;i<=4;i++){
			a[i]=0;
		}
		for(int i=1;i<=4;i++){
			cout << a[i];
		}
		return 0;
	}
    a[3]=0;
    a[4]=0;
    for(int i=1;i<=4;i++){
	cout << a[i];
}
return 0;
}
