#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n;
	cin >> m;
	long long a[50000];
	for (int i1 = 0;i1 < n;i1++){
		cin>>a[i1];
	}	
	int x = 0;
	while(m > 0){
		if(a[x+1] - a[x] > 1){
			for(int i2 = 0;i2 <= x;i2++){
				a[i2] = a[i2] + 1;
				m = m - 1;
				if (m == 0){
					break;
				}
			}
		}else if(a[x+1] - a[x] == 1){
			for(int i3 = 0;i3 <= x;i3++){
				a[i3] = a[i3] + 1;
				m = m - 1;
				if (m == 0){
					break;
				}
			}
			x = x + 1;
		}else{
			break;
		}
	}		
	long long t;
	for (int i4 = 0;i4 < n;i4++){
		if (a[0] == a[i4]){
			t = t + 1;
		}
	}
	cout << t;
	return 0;
}
