#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int s,t=0,a,b;
	char n,m;

	cin >> s >> a >> n >> b >> m ;
	if(n==m){
		cout << t;
	}
	else{
		t = t+b;
		cout << t;
	}
		

	fclose(stdin);
	fclose(stdout);

	return 0;
}
