//GZ-J00145 贾景栎 遵义市第四中学
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[10010],k=1;
	queue<int>c;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)c.push(a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				c.pop();
				c.push(a[i]);
				k++;
			}
		}
	}
	for(int i=n;i>=1;i--)cout<<c.front()<<' ';
	return 0;
}

