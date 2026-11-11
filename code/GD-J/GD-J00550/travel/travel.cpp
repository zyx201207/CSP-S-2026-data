#include <bits/stdc++.h>
using namespace std;
int a,b;
char a1[10],b1[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> a1 >> b >> b1;
	if(a==b){
		cout << "1";
	}else {
		cout << "0";
		cout << "0";
		cout << "0";
		cout << "0";
		return 0;
	}
	int sum = a1[0]-48,sum1 = a1[1]-48;
	int sub = b1[0]-48,sub1 = b1[1]-48;
	int m = sum*10+sum1,n = sub*10+sub1;
	if(m==n){
		cout << "1" ;
	}else{
		//cout << m << " " << n;
		cout << "0";
		cout << "0";
		cout << "0";
		return 0;
	}
	int p = a1[2]-64,q = b1[2]-64;
	//cout << p << " " << q <<" ";
	if(p<=3&&q<=3 || p>=4&&q>=4){
		cout << "1";
		if(p>=4&&q>=4){
			cout << "1";
		}else if(p-q==1 || q-p==1){
			cout << "1";
		}else{
			cout << "0";
		}
	}else {
		cout << "0";
		cout << "0";
		return 0;
	}
}//1 11A 1 11A
