#include <bits/stdc++.h>
using namespace std;
struct Node{
	long long x;
	char y;
};Node a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0;
	cin >> n;
	int nn=n;
	for(int i=1;i<=n;i++){
		int xx;
		cin >> xx;
		char yy;
		cin >> yy;
		if(a[k].y==yy){
			nn-=1;
			a[k].x+=xx;
			
			continue;
		}
		else{
			++k;
		}
		
		a[k].x=xx;
		a[k].y=yy;
	}
	int sum=0;
	for(int i=1;i<=nn/2;i++){
		if(a[i].x==a[n+1-i].x && a[i].y==a[i+n-1].y) continue;
		
		sum+=max(a[i].x,a[i+n-1].x);
		
	
	}
	cout <<sum;
	return 0;
	
}
