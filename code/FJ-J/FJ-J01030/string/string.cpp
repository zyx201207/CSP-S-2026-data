#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char c;
}a[200005];
node b[200005];
int n,m,k,p[200005],cnt,ans=2E9,vis[300005],cnt2;
char c[200005];
bool cmp(node x,node y){
	if(x.c!=y.c){
		
	return x.c<y.c;
	}else{
		return x.x<y.x;
	}
}
long long l,r;
void dfs(int x){
	if(x>n){
		int f=0;
		for(int i=1;i<=cnt2/2;i++){
		//	cout<<c[i]<<" "<<c[n-i+1]<<endl;
			if(c[i]!=c[cnt2-i+1]){
				f++;
			}
		}
	//	cout<<endl;
		ans=min(ans,f);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			for(int j=1;j<=a[i].x;j++){
				c[++cnt2]=a[i].c;
			}
			dfs(x+1);
			cnt2-=a[i].x;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		k=max(k,a[i].x);
	}
	if(n<=10){
		dfs(1);
		cout<<ans<<endl;
	}else if(k==1){
		for(int i=1;i<=n;i++){
			p[a[i].c-'a'+1]++;
		}
		for(int i=1;i<=26;i++){
			if(p[i]%2==1){
				cnt++;
			}
		}
		if(cnt%2==1){
			
		cout<<(cnt-1)/2<<endl;
		}else{
			cout<<cnt/2<<endl;
		}
	}
	return 0;
}
