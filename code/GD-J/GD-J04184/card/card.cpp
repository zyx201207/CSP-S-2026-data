#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int la[N],fi[N];
int f[N];
vector<int>q[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int text=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])text=1;
		la[a[i]]=i;
		if(!fi[a[i]])fi[a[i]]=i;
		q[a[i]].push_back(i);
	}
	if(text==0){
		for(int i=1;i<=m;i++){
			cout<<la[a[i]]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		int las=la[i],fir=fi[i];
		if(q[i].size()!=2)continue;
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			if(fir<fi[j]&&las>la[j]){
				f[j]=max(f[j],fir);
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<la[i]-f[i]<<" ";
	}
	return 0;
}/*
4 3
1  2 1 3
*/
