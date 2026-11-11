#include<bits/stdc++.h>
using namespace std;
int a[200009];
int n,m;
int ans=0;
int p[50]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
bool A=1;
void dfs(int st,int tot,int cnt){//tot表示选了多少个,cnt表示按位与结果
	if(cnt<ans)return; 
	if(m-tot+st>n)return;
	if(st>n){
		if(tot==m){
			ans=max(ans,cnt);
		}return;
	}if(tot==m){
		ans=max(ans,cnt);
		return;
	}if(tot==0){
		dfs(st+1,tot,cnt);
		dfs(st+1,tot+1,a[st]);
	}
	else{
		dfs(st+1,tot,cnt);
		cnt=cnt&a[st];
		dfs(st+1,tot+1,cnt);
	}
}
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!A)continue;
		int k=a[i]+1;
		bool found=0;
		for(int i=1;i<=30;i++){
			if(k==p[i]){
				found=1;
			}
		}if(!found)A=0;
	}sort(a+1,a+1+n);
	if(A){
		cout<<a[m];
	}else{
		dfs(1,0,1);
		cout<<ans;
	}
	return 0;
}
