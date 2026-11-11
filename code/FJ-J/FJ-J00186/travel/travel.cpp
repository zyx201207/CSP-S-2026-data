#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin >> c >> s >> cc >> ss;
	//if(c=="01"||)
	if(c==cc){
		cout << "1";//
	}
	else{
		cout << "0000";
		return 0;
	}
	int n=s.size();
	for(int i = 0; i<n-1; i++){
		if(s[i]!=ss[i]){
			cout << "000";
			return 0;
		}
	}
	cout << "1";//
	char ch=s[n-1],chh=ss[n-1];
	if(ch>'C'&&chh>'C'){
		cout << "1";//
		if(ch==chh+2){
			cout << "1";
		}
		else if(chh==ch+2) cout << "1";
		else cout << "0";
	}
	else if(ch<='C'&&chh<='C'){
		cout << "1";
		if(ch==chh+1){
			cout << "1";
		}
		else if(chh==ch+1) cout << "1";
		else cout << "0";
	}
	else if((ch<='C'&&chh>'C')||(chh<='C'&&ch>'C')) cout << "00";
	else cout << "0";
	return 0;
}
