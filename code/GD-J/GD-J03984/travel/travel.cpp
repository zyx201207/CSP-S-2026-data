#include<iostream>
#include<cstring>
#define memset(dest, val, n) __builtin_memet(dest, val, n)
#define fillinf(dest) memset((dest), 0x3f, sizeof(dest));
#define fillninf(dest) memset((dest), 0xc0, sizeof(dest));
#define fillzero(dest) memset((dest), 0, sizeof(dest));
#define fropen(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
#define closeios() ios::sync_with_stdio(false);cin.tie(0)
template<typename... Args>
void errorf(const char* format, Args... arg){fprintf(stderr, format, arg...);}
#define int2ll 0
#if int2ll
#define int long long
#define intEx signed
#else
#define ll long long
#define intEx int
#endif
using namespace std;

const int maxn=114514;
string a, b, x, y;

intEx main(){
	fropen("travel");
	// closeios();
	cin >> a >> b >> x >> y;
	if(a==x){
		cout << "1";
		if(b[0]==y[0]&&b[1]==y[1]){
			cout << "1";
			if(b[2]>='D'&&y[2]>='D'||b[2]<='C'&&y[2]<='C'){
				cout << "1";
				if(b[2]>='D'||__builtin_abs(b[2]-y[2])==1){
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}