#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n;
	long long bd,plu=0,top=0;
	char bdd;
	cin >> n;
	char a[1000000000];
	for(int i=0;i<n;i++){
		cin >> bd >> bdd;
		plu+=bd;
		for(int j=0;j<bd;j++){
			a[top]=bdd;
		}
	}
	int ans=0;
	for(int i=0;i<plu;i++){
		if(a[i]!=a[plu-i]){
			ans++;
		}
	}
	cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}