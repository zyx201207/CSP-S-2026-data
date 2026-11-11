#include<iostream>
#include<math.h>
using namespace std;

typedef long long  ll;
ll n, dif=0,f=0,b=0;
ll a[(int)2e5+5];
char c[(int)2e5+5];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i] >> c[i];
		if(c[i] == c[i-1]) {
			a[i-1]+=a[i];
			n--,i--;
		}
	}

	if(n==1) {
		cout << 0 << endl;
		return 0;
	}
//	cerr << "n: " << n << endl;
	f=1,b=n;
	while(f<b){
		if(a[f] == a[b]){//数量相等 
			if(c[f]==c[b]){// same char 
				f++,b--;
			}else{// diff char
				dif+=a[f];
				f++,b--;
			}
		}else if(a[f]>a[b]){//前面大 
			if(c[f]==c[b]){//same char
				a[f]-=a[b];
				b--;
			}else{//diff char
				dif += a[b];
				a[f]-=a[b];
				b--;
			}
		}else{//后面大 
			if(c[f]==c[b]){ //same char
				a[b]-=a[f];
				f++;
			}else{// diff char
				dif += a[f];
				a[b]-=a[f];
				f++;
			}
		}
	}
	cout << dif << endl;
	return 0;
}

