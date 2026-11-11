#include<bits/stdc++.h>
using namespace std;
int a[200009],b[1050000],c[100000];
int n,m,mx=INT_MIN;
void dfs(int p,int s,int sum){
	if(sum==0){
		/*for(int i=1;i<=m;i++){
			cout<<c[i]<<' ';
		}
		cout<<"11\n";*/
		//cout<<sum<<' '<<p<<'\n';
		mx=max(sum,mx);
		sum=INT_MAX;
		return;
	}
	if(p>m){
		/*for(int i=1;i<=m;i++){
			cout<<c[i]<<' ';
		}
		cout<<'\n';*/
		//cout<<sum<<' '<<p<<'\n';
		mx=max(sum,mx);
		sum=INT_MAX;
		return;
	}
	
	for(int i=s+1;i<=n;i++){
		//if(b[a[i]]==1)continue;
		//b[a[i]]=1;
		c[p]=a[i];
		//cout<<sum<<' '<<p<<' '<<a[i]<<'\n';
		dfs(p+1,i,sum&a[i]);
		//cout<<sum<<'m'<<p<<'m'<<a[i]<<'\n';
		//b[a[i]]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,0,INT_MAX);
		cout<<mx;
	}
	else if(m==1){
		cout<<a[n];
	}
	else if(n==m){
		int sum=INT_MAX;
		for(int i=1;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}
	//cout<<int(pow(2,20));
	
	return 0;
}
