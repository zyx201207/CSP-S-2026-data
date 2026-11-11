//GZ-J00546 遵义周林学校 杨莒粞  
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct {
	ll number;
	char remember;
}a[20003];

int main ()  {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,sam = 0,sum = 0,t,d;
	cin >> n;
	for (ll i= 1;i <= n;i++) {
		cin >> a[i].number >> a[i].remember ;
		sam += a[i].number ;
	}
	bool k= false;
	if (sam % 2 == 0) sam = sam / 2;
	else  {
		sam = sam / 2 + 1; k = true;
	}
	for (ll i = 1;i <= n;i++) {
		sum += a[i].number ;
		if (sum >= sam)  {
			t = i; d = sum - sam ;break;
		}	
	}
	ll i = t,j = t,m = 0;
	for (;;) {
		if (i == t && j == t) {
			if (k) a[j].number -= 1;
			if (d == 0) {
				j++;
			} else if (d == a[i].number - d) {
			    a[j].number =a[i].number -  d; i--;
			}else if (d > a[i].number - d) {
				a[j].number = 2 * d - a[i].number; i--;
			} else {
				a[i].number = a[i].number - 2 * d; j++;
			}
		} else if (a[i].remember == a[j].remember) {
			if  (a[i].number == a[j].number) {
			 i--; j++;
		    } else if (a[i].number < a[j].number) {
			 a[j].number -= a[i].number  ; i--; 
		    } else if (a[i].number > a[j].number ){
			 a[i].number -= a[j].number ; j++;
		    }
	    } else{
	    	if  (a[i].number == a[j].number) {
			 m += a[i].number;i--; j++; 
		    } else if (a[i].number < a[j].number) {
			 a[j].number -= a[i].number  ; m += a[i].number; i--; 
		    } else if (a[i].number > a[j].number ){
			 a[i].number -= a[j].number ; m += a[j].number; j++;
		    }
		}
		if (i == 0 || j == n + 1) break; 		   
	} 
	cout << m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
