//GZ-J00386 观山湖中学 吴昆灿 
#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int a[n+5];
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i] > 124816326412825651210242048409681921638432768655361310722621445242881000000){
			cout << 0;
			return 0;
		}
	}
	sort(a,a+n);
	sum=a[n-1];
	for(int i=1;i<m+1;i++){
		sum = sum & a[n-i];
	}
	cout << sum;
	return 0;
}
