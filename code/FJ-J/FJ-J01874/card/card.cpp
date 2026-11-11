#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],cnt[300001],f;
queue<long long> x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			x.push(a[j]);
		for(int l=i;l<=n;l++){
			f=x.size();
			for(int j=1;j<=f;j++){
				if(x.front()==a[l]){
					for(int k=j;k<=f;k++)
						x.pop();
					break;
				}else{
					x.push(x.front());
					x.pop();
				}
			}
			x.push(a[l]);
		}
		while(x.size()){
			cnt[x.front()]++;
			x.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<' ';
	return 0;
}
