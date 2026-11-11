#include<bits/stdc++.h>
using namespace std;

void mplus(int mid,int x[]);
void merge(int l,int r,int x[]);
int n,m,ans;
int main(){
	vector<int> atmp;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		atmp.push_back(tmp);
	}
	int a[n+1];
	for(int i=0;i<n;i++){
		a[i+1]=atmp[i];
	}
	sort(a+1,a+n+1);
	merge(1,n,a);
	cout<<ans; 
	return 0;
}
void mplus(int mid,int x[]){
	int i=mid-1,cnt=m,anstmp=0;
	while(cnt>0&&i>0){
		cnt-=x[mid]-x[i];
		i--;anstmp++;
	}
	if(cnt==0)anstmp+=1;
	ans=max(ans,anstmp);
}
void merge(int l,int r,int x[]){
	if(l<r){
		int mid=(l+r)/2;
		mplus(mid,x);
		merge(l,mid,x);
		merge(mid+1,r,x);
	}
}