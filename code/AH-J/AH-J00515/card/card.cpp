#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<=500){
		int a[501],b[201];
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i<=200)	b[i]=0;
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}else{
		int a[200001],b[100005],c[100005];
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[a[i]]++;
		}
		for(int i=1;i<=m;i++)
			b[i]%=2;
		for(int i=1;i<=m;i++)
			if(b[i]==1)
				c[i]++;
		for(int i=1;i<=n;i++){
			if(b[a[i]]==0){
				b[a[i]]=1;
			}else{
				b[a[i]]=0;
			}
			for(int i=1;i<=m;i++){
				c[i]+=b[i];
			}
		}
		for(int i=1;i<=m;i++)	cout<<c[i]<<" ";
	}
	return 0;
}
