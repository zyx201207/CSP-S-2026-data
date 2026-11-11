#include<bits/stdc++.h>
using namespace std;
int n,m;
int tot,er[33]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
bool ansa[33];
int a[200010],ans=0;
bool b[200010][38];
bool c[200010];
bool pan=1;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if((a[i]&er[j])==er[j]) b[i][j]=1;
		}
	}
	for(int i=30;i>=0;i--){
		tot=0;
		for(int j=1;j<=n;j++){
			if(b[j][i]==1&&!c[j]){
				tot++;
			}else if(pan) c[j]=1;
		}
		if(tot>=m){
			pan=0;
			ansa[i]=1;
			for(int k=1;k<=n;k++){
				if(b[k][i]==1&&!c[k]){
					tot++;
				}else c[k]=1;
			}
		}else{
			if(pan){
				for(int j=1;j<=n;j++) c[j]=0;
			}
		}
	}
	for(int i=31;i>=0;i--){
		if(ansa[i]) ans+=er[i];
	}
	cout<<ans;
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
