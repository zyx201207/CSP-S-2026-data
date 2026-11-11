#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n,m;
int  a[N];
bool b[N][40];//二进制表 
bool c[N];//是否已被淘汰 
bool ans[40];
void pre(){
	for(int i=1;i<=n;i++){
		int tmp=a[i];
		int j=0;
		while(tmp>0){
			j++;
			b[i][j]=(tmp&1);
			tmp>>=1;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	pre();
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=10;j++){
			cout<<b[i][j];
		}
		cout<<'\n';
	}*/
	for(int j=32;j>=1;j--){//遍历二进制数位 
		int cnt=0;
		for(int i=1;i<=n;i++){//遍历数字
			if(c[i])continue; 
			cnt+=b[i][j];
		}
		//cout<<cnt<<'\n';
		if(cnt>=m){
			for(int i=1;i<=n;i++){//淘汰不符合的数 
				if(!b[i][j] && !c[i]){ 
					c[i]=1;
				}
			}
			ans[j]=1;
		}
	}
	
	int res=0;
	for(int i=1;i<=32;i++){//答案转二进制 
		res+=ans[i]*pow(2,i-1);
		//cout<<ans[i];
	}
	cout<<res;
	return 0;
}
