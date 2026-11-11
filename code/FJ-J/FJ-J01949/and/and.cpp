#include<bits/stdc++.h>
using namespace  std;

int n,m,ans,k;
int a[200005],b[200005],vis[200005],xin[105];

void init(){
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	cout<<endl;
}

void dfs(int s,int ii){ 
//	cout<<n<<" "<<s<<endl;
//	cout<<s<<" "<<ii<<" "<<b[s]<<endl;
	if(s==m){
		if(b[s]>ans){
			ans=b[s];
		}
		return;
	}
	for(int i=ii+1;i<=n-s+2;i++){
		b[s+1]=b[s] & a[i];
		vis[s+1]=i;
		dfs(s+1,i);
	}
}

void f(){
	for(int i=1;i<=n-m+1;i++){
		b[1]=a[i];
		vis[1]=i;
		dfs(1,i);
	}
	cout<<ans;
}

int pan(){
	for(int i=1;i<=n;i++){
		if(a[i]>=4){
			return 0;
		}
	}
	return 1;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(pan()){
		for(int i=1;i<=n;i++){
			if(a[i]==3){
				xin[3]++;
			}else if(a[i]==2){
				xin[2]++;
			}else if(a[i]==1){
				xin[1]++;
			}
		}
		if(xin[3]>=m){
			cout<<3;
		}else{
			if(xin[3]+xin[2]>=m){
				cout<<2;
			}else{
				if(xin[3]+xin[1]>=m){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}else{
		if(n==m){
			int q=a[1];
			for(int i=2;i<=n;i++){
				q=q & a[i];
			}
			cout<<q;
			return 0;
		}
	}
	if(n<=20){
		f();
	}
	return 0;
}
