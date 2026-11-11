#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		int sum=a[1]&a[2];
		for(int i=3;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=-1,index1=0,index2=0;
	for(int j=1;j<=n;j++){
		for(int k=j+1;k<=n;k++){
			if(a[j]&a[k]>maxn){
				maxn=a[j]&a[k];
				index1=j;
				index2=k;
			}
		}
	}
	b[index1]=1;
	b[index2]=1;
	for(int i=1;i<=m-2;i++){
		int maxnn=0,index3;
		for(int j=1;j<=n;j++){
			if(b[j]==1){
				continue;
			}
			if(maxn&a[j]>maxnn){
				index3=j;
				maxnn=maxn&a[j];
			}
		}
		maxn=maxnn;
		b[index3]=1;
	}
	cout<<maxn;
	return 0;
}
