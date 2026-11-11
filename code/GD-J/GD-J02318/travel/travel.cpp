#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int a1 = 0,b1 = 0,c1=  0,d1 = 0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	
	cin >> a >> b >> c >> d;
	
	if(a == c) a1 = 1;
	string x="",y="";
	int x1 = 0,y1 = 0;
	
	for(int i=0;i < b.size();i ++){
		if(b[i] - '0' >= 0 && b[i] - '0' <= 9){
			x += b[i];
		}else{
			x1 = (b[i] - 'A' + 1);
		}
	}
	
	for(int i=0;i < d.size();i ++){
		if(d[i] - '0' >= 0 && d[i] - '0' <= 9){
			y += d[i];
		}else{
			y1 = (d[i] - 'A' + 1);
		}
	}
	
	if(x == y && a1 == 1) b1 = 1;
	
	if(((x1 >= 1 && x1 <= 3) && (y1 >= 1 && y1 <= 3)) && b1 == 1 && a1 == 1)c1 = 1;
	if(((x1 >= 4 && x1 <= 5) && (y1 >= 4 && y1 <= 5)) && b1 == 1 && a1 == 1)c1 = 1;
	
	if((x1 + 1 == y1)){
		int s = 1;
		if((x1 == 3 || x1 == 4) && (y1 == 3 || y1 == 4)){
			s = 0;
		}else{
			if(s == 1) d1 = 1;
		}
	}
	
	cout << a1 << b1 << c1 << d1;
	
	
	return 0;
}
