#include <bits\stdc++.h>
using namespace std;
struct zu{
	int s;
	char u;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,o,l = 0,y = 0;
	char p;
	cin >> n;
	zu a[n];
	for(int i= 0 ;i <n;i++){
		cin >> o >> p;
		l += o;
		//cout << l << endl<< o << endl;
		a[i].s = o;
		a[i].u = p;
	}
	
		int i = 0,m = n-1,r = 0;
	while(r == 0){
			if(a[i].s == 0){
				i++;
			}if(a[m].s == 0){
				m--;
			}
			if(i == m){
				r = 78;
			}
			
			if(a[i].u != a[m].u){
				if (a[i].s >= a[m].s){
					a[i].s -= a[m].s;
					y += a[m].s;
					a[m].s = 0;
					
				}else{
					a[m].s -= a[i].s;
					y += a[i].s;
					a[i].s = 0;
					
				}
			}else{
				if (a[i].s >= a[m].s){
					a[i].s -= a[m].s;
					a[m].s = 0;
			
				}else{
					a[m].s -= a[i].s;
					a[i].s = 0;
					
				}
			}
		
	}
	cout << y;
	
	
	
	
	
	
	
	
	

	return 0;
}
