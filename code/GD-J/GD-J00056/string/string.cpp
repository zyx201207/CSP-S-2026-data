#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s = 0,e = 0,zm[100005],c = 0,y = 0;
	char zmm[100005];
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> zm[i];
		s += zm[i];
		cin >> zmm[i];
	}
	if (s%2 == 0){
		s /= 2;
	}else{
		s -= 1;
		s /= 2;
	}
	int w = n-1;
	while (y < s && e != w){
		if (zmm[e]==zmm[w]){
			if (zm[e] > zm[w]){
				zm[e] -=zm[w];
				w--;
				y+=zm[w];
			}else if (zm[e] < zm[w]){
			    zm[w] -=zm[e];
				e++;
				y+=zm[e];
			}else{
				e++;
				w--;
				y+=zm[e];
			}
		}else{
		    if (zm[e] > zm[w]){
				zm[e] -=zm[w];
				w--;
				y+=zm[w];
				c+=zm[w];
			}else if (zm[e] < zm[w]){
			    zm[w] -=zm[e];
				e++;
				y+=zm[e];
				c+=zm[e];
			}else{
				e++;
				w--;
				y+=zm[e];
				c+=zm[e] ;
		    }
		}
	}
	cout << c;
	return 0;
}
