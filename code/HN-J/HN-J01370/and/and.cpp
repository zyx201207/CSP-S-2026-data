#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		
	}
	for(int i = 1; i<= n; i++){
		cnt = a[i];
		if(cnt < a[i+1])
		sort(cnt,a[i+1]);
			
			
		}
	}
	cout <<cnt;

}
