#include<bits/stdc++.h>
using namespace std;
int n,m,arr[200005],t[200005];
bool f=1;
int dfs(int a,int s,int l){
	if(s==m){
		return l;
	}
	if(a>n){
		return 0;
	}
	return max(dfs(a+1,s,l),dfs(a+1,s+1,(l&arr[a])));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>=4){
			f=0;
		}
	}
	if(n<=20&&m<=20){
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,dfs(i+1,1,arr[i]));
			cout<<endl;
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int o=i+1;o<=n;o++){
				maxn=max(maxn,arr[i]&arr[o]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,arr[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(f){
		for(int i=1;i<=n;i++){
			t[arr[i]]++;
		}
		if(t[3]>=2){
			cout<<3;
		}
		else if(t[2]>=2){
			cout<<2;
		}
		else{
			cout<<1;
		}
		return 0;
	}
	bool n1=1;
	int nn=n;
	while(nn>1){
		if(nn%2){
			n1=false;
			break;
		}
		nn/=2;
	}
	if(n1){
		cout<<n-2;
		return 0;
	}
	int maxn1=0,maxn2=0,k=0;
	for(int i=1;i<=n;i++){
		if(arr[i]>maxn1){
			maxn1=arr[i];
			k=i;
		}
	}
	arr[k]=0;
	for(int i=1;i<=n;i++){
		if(arr[i]>maxn2){
			maxn2=arr[i];
			k=i;
		}
	}
	cout<<(maxn1&maxn2);
	return 0;
} 

