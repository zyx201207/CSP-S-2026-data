#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[2005],sum = 0;
string s[2005];
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)	cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	if(m == 1){
		cout << a[1];
	}
	else{
		sum = a[1];
		for(int i = 2;i <= m;i++){
			if(sum == 0)	break;
			else if(sum == 3 && a[i] == 3)	sum = 3;
			else if(sum == 3 && a[i] == 2)	sum = 2;
			else if(sum == 3 && a[i] == 1) 	sum = 1;
			else if(sum == 3 && a[i] == 0)	sum = 0;
			else if(sum == 2 && a[i] == 3)  sum = 2;
			else if(sum == 2 && a[i] == 2)	sum = 2;
			else if(sum == 2 && a[i] == 1)	sum = 0;
			else if(sum == 2 && a[i] == 0) 	sum = 0;
			else if(sum == 1 && a[i] == 3)  sum = 1;
			else if(sum == 1 && a[i] == 2)	sum = 0;
			else if(sum == 1 && a[i] == 1)	sum = 1;
			else if(sum == 1 && a[i] == 0) 	sum = 0;
		}
		cout << sum;
	}
	return 0;
}
