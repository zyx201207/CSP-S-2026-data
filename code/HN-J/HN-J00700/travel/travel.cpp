#include<bits/stdc++.h>
using namespace std;
const int N=200001;
typedef long long ll;
#define endl '\n'

string a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> a >> b >> c >> d;
	int c1=b[2]-'A',c2=d[2]-'A';
	if (a!=c)
		cout << "0000\n";
	else if (b[0]!=d[0] || b[1]!=d[1])
		cout << "1000\n";
	else if (!((c1<=2 && c2<=2) || (c1>2 && c2>2)))
		cout << "1100\n";
	else if (abs(c1-c2)!=1)
		cout << "1110\n";
	else
		cout << "1111\n";
	return 0;
}

