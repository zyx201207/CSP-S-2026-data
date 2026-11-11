#include<bits/stdc++.h>
using namespace std;

int a[212345];
int t[212345];
int solve_TMLROCK(int n,int m,int k) {
	if(k < 0) return 0;
	int n2 = 0;
	for(int i = 0; i<n; ++i) if(a[i] & (1<<k) )t[n2++] = a[i];
	if(n2 >= m) {
		for(int i = 0; i<n2; ++i) a[i] = t[i];
		return (1<<k) | solve_TMLROCK(n2,m,k-1);
	} else return solve_TMLROCK(n,m,k-1);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i =0; i<n; ++i) cin>>a[i];
	cout<<solve_TMLROCK(n,m,30);
	return 0;
}

