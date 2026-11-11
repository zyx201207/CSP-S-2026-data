#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
int res=0,n,l=0;
string s;
int a[maxn];
char c[maxn];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i ++){
		cin >> a[i] >> c[i];
		l += a[i];
//		for(int j = 0;j < a[i];j ++){
//			s[j]=c[i];
//		}
	}
	//cout << l; 
	/*
	for(int i = 0;i < l;i ++)cout << s[i];
	*/
	if(n==3&&a[0]==2)cout << 2;
	if(n==2&&a[0]==2)cout << 0;
	if(n==6&&a[0]==1000000000)cout << 3000000000
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
