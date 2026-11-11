#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w".stdout);
	int n,m,a[100005];
	cin>>n>>m;
	string c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int h=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]==a[j+1]-1||a[j]==a[j-1]+1){
				continue;
			}
			else{
			c[h]=a[i];
			h++;
			}
		}
	}
	for(int i=1;i<=c.length();i++){
		int num=0;
		for(int j=1;j<=m;j++){
			if(c[i]==j){
				num++;
			}
		}
		cout<<num;
	}
	return 0;
}
