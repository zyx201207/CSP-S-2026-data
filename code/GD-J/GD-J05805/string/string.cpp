#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,n1=0,x=0; cin >> n;
	int a[n] = {}; string b[n] = {}; 
	
	for(int i=0;i<n;i++){
		cin >> a[i];
		cin >> b[i];
	}
		
	for(int u=0;u<n;u++){
		n1 += a[u];
	}
	string c[n1] = {};
	string d[n1] = {};
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			c[x] = b[i];
			x++;	
		}
	}
//	for(int i=0;i<n1;i++){
//		cout << c[i];
//	}
//	cout << endl;
	int y,p,o=n1/2;
	if((n1 % 2) != 0){
		while(o >= 0){
			o - a[p];
			p++;
		}
		a[p] - 1;
		for(int i=0;i<(n1/2);i++){
			d[i] = c[i];
			y++;
		}
		for(int i=(n1/2)+1;i<n1;i++){
			d[i] = c[i];
			y++;
		}
	}
	else{
		y = n1;
	}
//	for(int i=0;i<n1;i++){
//		cout << d[i];
//		
//	}
	int y1,y2;string s[n1/2] = {};
	y2 /= 2;
	
	y1 = y2-a[0];
	if(y1 = 0){
		if(((y) - a[1]) == 0){
			cout << "0";
		}
		else{
			cout << y;
		}
	}
	else if(y1 < 0){
		cout << y + y1;
	}
	else if(y1 > 0){
		if(y1 > y){
			cout << y;
		}
		else if(y1 < y){
			cout << y1;
		}
		else{
			cout << y1;
		}
	}

return 0; 
}






