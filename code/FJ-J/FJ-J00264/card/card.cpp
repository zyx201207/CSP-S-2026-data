#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005],n,m;
vector<int>c;
void ju(int x){
	int cnt=0,y;
	for(int i=x;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			if(c[j-1]==a[i]){
				y=cnt;
				for(int k=j;k<=y;k++){
					c.pop_back();
					cnt--;
				}
				break;
			}
		}
		c.push_back(a[i]);
		cnt++;
	}
	for(int i=1;i<=cnt;i++){
		b[c[i-1]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		c.clear();
		ju(i);
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

