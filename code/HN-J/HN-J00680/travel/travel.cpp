#include<bits/stdc++.h>
using namespace std;
string z,x,c,v;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> z >> x >> c >> v;
	if(z == c)
	{
		cout << 1;
	 } 
	 else
	 {
	 	cout << 0;
	 }
	 if(x[0] == v[0] && x[1] == v[1])
	 {
	 	cout << 1;
	 }
	 else
	 {
	 	cout << 0;
	 }
	 if((x[2] >= 'A' && v[2] <= 'C') && (x[2] >= 'D' && v[2] <= 'F'))
	 {
	 	cout << 1;
	 }
	 else
	 {
	 	cout << 0;
	 }
	 if((x[2] == 'A' || v[2] == 'B') && (x[2] == 'B' || v[2] == 'C') && (x[2] == 'D' || v[2] == 'F'))
	 {
	 	cout << 1;
	 }
	 else
	 {
	 	cout << 0;
	 }
	return 0;
}
