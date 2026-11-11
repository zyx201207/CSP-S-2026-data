#include<bits/stdc++.h>
using namespace std;

int n;
int c[10001];
char f[10001];
int p , m , n;
char a[100001];
char b[100001];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> c[i] >> f[i];
	}
	if(n == 0 || n == 1){
	cout << 0;
	return 0;
    }
	for(int i = 1;i < n;i++){
		if(c[i] != c[i - 1]) m = -1; 
		if(f[i] != f[i - 1]) p = -1;
	}
	
	if(p != -1) {
	cout << 0; 
    }
	return 0;
}
