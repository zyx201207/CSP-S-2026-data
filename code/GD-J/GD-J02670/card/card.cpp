#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+2];
	int b[m+2]={0};//点数数量 
	for (int i=1;i<=n;i++)
		cin >> a[i];
	for (int i=1;i<=n;i++){
		bool c[m+2]={0};//之前是否输入 
		string x;
		for (int j=i;j<=n;j++){
			if (!c[a[i]]) x+=a[i];
			else{
				int y = x.find(to_string(a[i]));
				x = x.substr(0,y);
				x += a[i];
				c[a[i]]=1;
			}
			for (int k=0;k<x.size();k++){
				b[x[k]]++;
			}
		}
		
	}
	for (int i=1;i<=m;i++){
		cout << b[i] << ' ';
	}
	return 0;
}
