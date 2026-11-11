#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9,M=3e5+9;
int n,m,a[N],cnt[N],lst[N];
map<int,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(!mp[a[i]]){
		//	cout<<i<<" "<<i+1<<endl;
			lst[i]=i+1;
		}
		else{
			lst[i]=mp[a[i]]+1;
		//	cout<<i<<" "<<mp[a[i]]+1<<endl;
			
		}
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
	//	cout<<lst[i]<<" ";
		int l=i;
		for(;l<=n;){
			cnt[a[l]]++;
			l=lst[l];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/