#include<bits/stdc++.h>
using namespace std;
vector<int>b;int k=0;
vector<int>id;
vector<int>sum;
int a[500005],n,m;
int j=1e12,ans=0,maxans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int maxa=-1e12;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		j=min(j,a[i]);
	}
	sort(a+1,a+n+1);
	b.push_back(0);
	id.push_back(0);
	sum.push_back(0);
	for(int i=1;i<=n;i++){
		if(id[k]!=a[i]){
			b.push_back(0);
			id.push_back(a[i]);
			k++;
		}
		b[k]++;
	}
	for(int i=1;i<=k;i++){
		sum.push_back(sum[i-1]+b[i]);
	}
	int l=1,r=1;
	while(r<k){
	    if(j==id[r+1]) r++;
		if(m>=sum[r]-sum[l-1]||j==id[r]&&m>=sum[r-1]-sum[l-1]){
			if(j==id[r])m-=sum[r-1]-sum[l-1];
			else m-=sum[r]-sum[l-1];
			ans=sum[r]-sum[l-1];
			if(l>=2) ans+=m/(j-id[l-1]);
			j++;
		}else{
			m+=(j-1-id[l])*b[l];
			l++;
		}
		maxans=max(maxans,ans);
	}
	cout<<maxans;
	return 0;
}
