#include<bits/stdc++.h>
using namespace std;
int n,x;char a[200005];
int main (){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n;
	int nod=0;char li;
	for(int i=1;i<=n;i++){
		cin >> x >>li;
		while(x--){
			a[++nod]=li;
		}
	}
	int flag=0;
	for(int i=1;i<nod;i++){
		if(a[nod]!=a[nod+1]) {
			flag=1;break;
		}
	}
	if(!flag){
		cout << 0;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=nod/2;i++){
		if(a[i]!=a[nod+1-i]) {
			a[nod+1-i]==a[i];
			ans++;
		}
	}
	cout <<ans;
	return 0;
}
