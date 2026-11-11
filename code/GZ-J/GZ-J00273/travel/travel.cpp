//GZ-J00273 樊辰熙
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,ss,s2,ss2;
	cin >> s >> ss >> s2 >> ss2;
	if(s!=s2){
		cout << "0000";
		return 0;
	}
	cout << '1';
	string a1="",a2="";char b1=ss[2],b2=ss2[2];
	long long x=0,y=0,m=10;
	for(int i=0;i<2;i++){
		a1+=ss[i];
		a2+=ss2[i];
		x+=(ss[i]-'0')*m;
		y+=(ss2[i]-'0')*m;
		//cout << '*'<< x << '/' << y;
		m/=10;
	}
//	cout << endl << a1 << ' ' << a2 << ' ' << x << ' ' << y << ' ' << b1 << ' ' << b2 << endl;
	if(a1==a2 ) cout << '1';
	else{
		cout <<'0';
	}
	if(b1<='C' and b2<='C' and x==y) cout << '1';
	else if(b1>'C' and b2>'C' and x==y) cout << '1';
	else cout <<'0';
	if(((b1+1!='D' and b1+1==b2) or (b1-1!='C' and b1-1==b2) or b1==b2) and x==y){
		cout << 1;
	}
	else if((x-1==y or x+1==y or x==y) and b1==b2) cout << 1;
	else cout << '0';

	return 0;
}
