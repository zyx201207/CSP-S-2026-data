#include<bits/stdc++.h>
using namespace std;
int l[500005];
int ans[500005];
void a(int i,int n,int x){
	ans[500005]={0};
	for(;i<=n;i++){
		ans[i]=l[i+x];
	}
}
void f(int i,int n){
	int j,x;
	for(;i<=n;i++){
		for(j=i;j<=n;j++){
			if(l[j]=l[i]){
				x=j-i;
				a(i,n,x);
			}
		}
		a(i,n,0);
	}
}
bool find(int i,int n){
	for(int j=1;j<=n;j++){
		if(ans[j]==i){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	for(int i=1;i<=m;i++){
		sum=0;
		for(int j=i;j<=n;j++){
			f(j,n);
			if(find(i,n)) sum++;
		}
		cout<<sum<<" ";
	}
	return 0;
}
