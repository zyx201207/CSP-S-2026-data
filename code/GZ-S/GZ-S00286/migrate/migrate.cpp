//华东师范大学附属贵阳学校 陈睿阳 GZ-S00286 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
unsigned long long c,t,n,d,k=1,cnt=0;
unsigned long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> a[i];
			if (i==2) c=a[i]-a[i-1]; 
			if (i>2 && a[i]-a[i-1]!=c) c=-1; 
		}
		if (a[2]-a[1]<=d && c!=-1){
			cout << n-d-1;
		}
		else cout << (n-1)*(n-2)/2;
	}
	return 0; 
}
