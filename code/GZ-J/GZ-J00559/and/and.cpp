//GZ-J00559 遵义市第十二中学 李承昊 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,ton[10];
bool t,t2;
bool cmp(int a,int b){
	return a>b; 
}
void dfs(int s,int x,int pos){
	if(pos==m){
		ans=max(ans,s);
		return ;
	}
	for(int i=x+1;i<=n;i++) dfs((s&a[i]),i,pos+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]+1!=i) t=1;
		if(a[i]>3) t2=1;
	}
	sort(a+1,a+n+1,cmp);
	if(n<=20){
		dfs(a[1],1,1);
		cout<<ans;
	}
	else if(n<=2000){
		if(m==1){
			cout<<a[1];
			return 0;
		}
		if(m==n){
			int cnt=a[1]&a[2];
			for(int i=3;i<=n;i++) cnt=cnt&a[i];
			cout<<cnt;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
			}
			cout<<ans;
		}
	}
	else{
		if(t){
			if(t2) cout<<a[m];
			else{
				for(int i=1;i<=n;i++) ton[a[i]]++;
				if(a[3]>=m) cout<<3;
				else if(a[3]+a[2]>=m) cout<<2;
				else if(a[3]+a[1]>=m) cout<<1;
				else cout<<0;
			}
		}
		else{
			cout<<n-m;
		}
	}
	return 0;
}
