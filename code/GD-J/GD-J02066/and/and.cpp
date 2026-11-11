#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],ans[N],maxn=0;
int n,m;
bool flag[N]; 
void retra(int sum,int num){
	if(num==m) maxn=max(sum,maxn);
	for(int i=1;i<=n;i++){
		if(flag[i]==true) continue;
		
		flag[i]==true;
		retra(sum&a[i],num+1);
		flag[i]==false;
		retra(sum,num);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		flag[i]=true;
		retra(a[i],1);
		flag[i]=false;
	}
	cout<<maxn;	
	return 0;
}
