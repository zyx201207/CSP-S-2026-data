#include<bits/stdc++.h>
using namespace std;
const int NN=5e5+10,MM=3e5+10;
int n,m,a[NN],v[MM],diff_[NN],ok_[NN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int la=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(v[a[i]]==0)v[a[i]]=i;
		else{
			diff_[v[a[i]]]-=la;
			diff_[v[a[i]]+1]+=v[a[i]];
			diff_[i]-=v[a[i]];
			la=v[a[i]];
			v[a[i]]=i;
		} 
	}
	for(int i=1;i<=n;i++){
		ok_[i]=diff_[i]+ok_[i-1];
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]-ok_[i]<<' ';
	}
	return 0;
} 
