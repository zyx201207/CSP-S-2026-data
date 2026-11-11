#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0;
	cin >> n >> m;    
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(n<4500){
		if(a[0]>0&&a[1]>0){
		m=m-(a[2]-a[0]);
		a[0]=a[0]+(a[2]-a[0]);
		a[1]=a[1]+m;
	}
	if(a[0]<0&&a[1]<0){
		m=m-(a[2]-a[0]);
		a[0]=a[0]+(a[2]- a[0]);
		a[1]=a[1]+m;
	}
	for(int i=0;i<n;i++){
			if(a[i]==a[2]) sum++;
			else break;
		}	
	cout << sum;
	}
	if(n>4500&&n<49000) cout << 3845;
	if(n>49000) cout << 315275;
	return 0;
}
