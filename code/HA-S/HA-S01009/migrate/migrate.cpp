#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
long long d;
int a[10001];
int q(int x,int y)
{
	int w=0;
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			if(a[j]>a[i]){
				int t=a[j]-a[i];
				if(t>y){
					if(t%y==1){
						w++; 
					}
				}
			}
			if(a[j]<a[i]){
				int t=a[i]-a[j];
				if(t>y){
					if(t%y==1){
						w++; 
					}
				}
			}
		}
	}
	return w;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out ","w",stdout);
	cin >> c >> t;
	for(int i=0;i<t;i++){
		cin >> n >> d;
		for(int j=0;j<n;j++){
			cin >> a[j];
		}
		ans=q(n,d);
		cout << ans/2 << endl;
	}
	return 0;
} 
