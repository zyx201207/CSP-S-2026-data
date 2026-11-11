#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	int n,m;
	cin>>n>>m;
	int d,q;
	cin>>d>>q;
	int a[1000000];
	int b[1000000];
	for (int i=1;i<=m;i++){
		cin>>a[i];
	}
	int c[1000000];
	int d[1000000];
	int e;
	for (int i=1;i<=n;i++){
		cin>>e;
		for (int j=1;j<=e*2;j++){
			if (j%2==0){
				cin>>d[i];
			}
			else{
				cin>>c[i];
			}
		}
	}
	int jiao;
	bool falg=1;
	for (int i=1;i<=e;i++){
		for (int j=1;j<=e;j++){
			if (d[i]==c[j]){
				jiao=d[i];
				flag=0;
				break;
			}
		}
		if (flag=0){
			break;
		}
	}
	for (int i=1;i<=q;i++){
		int aa,bb;
		cin>>aa>>bb;
		int di1,di2,di3,di4;
		for (int i=1;i<=e;i++){
			if (d[i]==aa){
				di1=1;
			}
		}
	}
} 
