#include<bits/stdc++.h>
using namespace std;
string R,X;//travel 1.0 
int r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> R >> x >> X;
	if (r!=x){ 
		cout << "0000";
		return 0;
	}
	else cout << "1"; 
	string a,b;
	for (int i=0;i<=1;i++)
		a+=R[i],b+=X[i];
	if (a==b) cout << "1"; 
	else {
		cout << "000"; 
		return 0;
	}
	char A=R[2],B=X[2];
	if (((A>='A' && A<='C') && (B>='A' && B<='C')) || ((A=='D' || A=='F') && (B=='D' || B=='F')))
		cout << "1";
	else{
		cout <<"00";
		return 0;
	}
	if (min(A,B)+1==max(A,B) || ((A=='D' && B=='F') || (A=='F' && B=='D')))
		cout << "1";
		else cout << "0";
	return 0;
} 
