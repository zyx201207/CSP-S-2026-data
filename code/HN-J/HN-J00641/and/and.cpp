#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k,x,f,o,y;
	
	int s[n+5];
	int a[50]
	cin >> n >> m;
	x=n;
	y=n;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		f=x*=(x-1);
		x--;
		
	}
	for(int i = 1;i <= m;i++)
		o=n*(n-1);
		n--
	k=f/o;
	
	for(int i = 1;i <= y;i++){
		char p = {};
		while(s[i]!=0){
			s[i] -= s[i]%2;
			p +=s[i]%2;
		
		
		
		
		
		}
	
		a[i] = p;
	}
	for(int i = 1;i <= k;i++){
		cout << max(a[i] and a[i+1],a[i] and a[i+2]);
	
	
	
	
	
	
	
	
	
	
	
	
	
}
