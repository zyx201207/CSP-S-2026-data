#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,b,c,d,bb,dd,bbb,ddd; 
	cin >> a >> b >> c >> d;
	if(a == c) cout << 1;
	else{
		cout << "0000";
		return 0;	
	}
	for(int i = 0;i < b.size() - 1;i ++) bb += b[i];
	for(int i = 0;i < d.size() - 1;i ++) dd += d[i];
	if(bb == dd) cout << 1;
	else {
		cout << "000";
		return 0; 
	} 
	bbb += b[b.size() - 1];
	ddd += d[d.size() - 1];
	if(bbb >= "D" && bbb <= "F" ){
		if(ddd >= "D" && ddd <= "F"){
			cout << "11";
			return 0;
		}
		else{
			cout << "00";
			return 0;
		}
	}else if(bbb >= "A" && bbb <= "C"){
		if(ddd >= "A" && ddd <= "C"){
			cout << 1;
		}else{
			cout << "00";
			return 0;
		}
	}
	
	if(bbb == "B" || ddd == "B") cout << 1;
	else cout << 0;
	return 0; 
}


