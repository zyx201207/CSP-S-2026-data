#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],c[300010];
stack<int>f;
//vector<int>f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		while(f.size())f.pop();
		for(int j=1;j<=m;j++)b[j]=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(f.size()&&f.top()!=a[j]){
					b[f.top()]--;
					f.pop();
				}
			}
			else{
				f.push(a[j]);
				b[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++)if(b[j])c[j]++;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
}
