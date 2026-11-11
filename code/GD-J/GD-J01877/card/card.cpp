#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
int b[N],t = 0;
int ct[N];
int ls[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		t = 0;
		for(int j = i;j <=n;j++){
			int fl =-1;
			if(ls[a[j]] <= t && b[ls[a[j]]] == a[j]) fl = ls[a[j]];
			if(fl==-1){
				b[++t] = a[j];
				ls[a[j]] = t;
			}else{
				t = fl;
				ls[a[j]]= t;
			}
		}
		for(int i = 1;i <= t;i++) ct[b[i]]++; 
	}
	
	for(int i = 1;i <= m;i++) cout << ct[i] << " "; 
	
	
	return 0;
}
/*
100+100+[40,100]+48 = [288,348]


*/

