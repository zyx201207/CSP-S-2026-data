#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int s[200005];
int flag[200005];
int maxn;
int num;
void DFS(int pos,int sum){
	if (pos==m+1){
		num=s[1];
		for (int i=2;i<=m;i++){
			num=int(num&s[i]);
		}
		maxn=max(maxn,num);
		return ;
	}
	for (int i=sum;i<=n-m+pos;i++){
		if (flag[i]==0){
			s[pos]=a[i];
			flag[i]=1;
			DFS(pos+1,i);
			flag[i]=0;	
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (m==1){
			maxn=max(a[i],maxn);
		}
	}
	if (m==n){
		maxn=a[1];
		for (int i=2;i<=n;i++){
			maxn=int(maxn&a[i]);
		}
	}
	DFS(1,1);
	cout<<maxn;
	return 0;
}
