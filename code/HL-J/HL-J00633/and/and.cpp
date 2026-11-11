#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,a,b,c,d,f;
	cin >> n >> m >> a >> b >> c >> d >> f;
	if(d>f){
		cout << f;
	}
	else{
		cout << d;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
