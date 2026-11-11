#include <bits/stdc++.h>
using namespace std;
int a[200005] ,b[200005];
char c[200005][35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x,j,f=0;
	cin >> n >>m>>j>>x;
	for(int i=1;i<=n;i++)
	{
		cin >> x;
		a[i] = x;
		f = max(f,x);
		j=0;
		while(x>0){
			j++;
			c[i][j] =x%2;
			x/=2;
		}
		cout<<x;
	}	
	return 0;
}