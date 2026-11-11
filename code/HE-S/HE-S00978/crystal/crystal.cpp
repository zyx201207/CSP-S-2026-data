#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int n,m;
	int a;
	cin >>n,m>>;
	for(i=1;i<=n;i++){
		int a[i];
		cin>>a[i]>>;
	}
	int b=0;
	int d=0;
	
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if a[j] > a[j+1]{
				b = a[j+1];
				a[j+1] = a[j];
				a[j] = b;
				b = 0;
			}
		}
	}
	int c=a[-1];

	
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if a[j]-a[i] >= 1 && a[j]-a[i] < c{
				c = a[j]-a[i];
			}
		}
	}
	
	
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if m == 0{
				for(i=1;i<=n;i++){
					for(j=i+1;j<=n;j++){
						if a[j]-a[i] == 0{
							d += 1;
						}
					}
				}
				cout<<d<<;
				dreak;
			}
			if a[j]-a[i] = c{
				a[i] += 1;
				m -= 1;
			}
		}
	}
	
	return 0;
}
