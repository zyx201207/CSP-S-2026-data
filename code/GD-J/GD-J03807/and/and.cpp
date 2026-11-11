#include<bits/stdc++.h>
using namespace std;

int main()
{
	//preopon("travel.in",w,stdin);
	//preopon("travel.out",r,stdout);
	int n,m,ma = 0;
	cin >> n >> m; 
	int a[n];
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int z,h = 0;
	for(int i = 0;i < n ;i++) {
		int c = 0;
		while(1){
			z =0;
			if(a[i] == 0){
				break;
			}
			if(a[i]%2 == 1 && a[i+1]%2==1){
				z = 1;
			}
			h += z * pow(2,c);
			a[i] = a[i]/2;
			a[i + 1] = a[i+1]/2;
			c++;
		}
		ma = max(h,ma);
	}
	cout << ma;
	return 0;
}
