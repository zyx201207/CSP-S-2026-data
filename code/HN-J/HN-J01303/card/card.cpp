#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m; 
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n>=5){
		cout << m << a[0] << n;
	}
	else{
		cout << n << m << a[0];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
	
}
