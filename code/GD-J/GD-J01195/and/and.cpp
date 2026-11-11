#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN],m,vis[MAXN];
vector<int> v;
int read(){
	char ch=getchar();int num=0;
	while(ch<'0' || ch>'9') ch=getchar();
	while('0'<=ch && ch<='9') num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		v.push_back(a[i]);
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			if((1<<i)&a[j]) cnt++;
		}
		if(cnt>=m){//ke yi yao zhe yi wei
			ans|=(1<<i);
			for(int j=1;j<=n;j++){
				if(!(a[j]&(1<<i))) vis[j]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
