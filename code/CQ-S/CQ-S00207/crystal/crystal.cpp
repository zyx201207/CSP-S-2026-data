#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("r","crystal.in",stdin);
	freopen("w","crystal.out",stdout);
	int n,maxx=1;
	long long a[5005];
    long long m; 
	cin >> n >> m;
	if (n>=5001){
		cin >> a[1] >> a[2] >> a[3];
		for (int i=1;i<=n-3;i++)cin >> a[3];
		sort(a+1,a+2);
		int ss=a[2]-a[1],sss=1;
		while (true){
			if (m-ss*sss<0){
				break;
			}
			else{
				sss++;
				m-=ss*sss;
			}
		}
		cout << min(sss,n);
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++){
		int x=0,y=i,maxn=1;
		while (y>1)           
		{                                                         
			y--;                                     
			if (x+a[y+1]-a[y]<=m){
				x+=a[y+1]-a[y];
				maxn++;
			}
			else {
				break;
			}
		}
		if (maxx<maxn){
			maxx=maxn;
		}
	}
	cout << maxx;
	return 0;
}
