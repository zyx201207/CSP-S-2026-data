#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+10;
int n,m,dian[M],ans[M],cc[M],k;
void chushihua(){
	for(int i=1;i<=n;i++){
		cc[i]=0;
	}
}
bool find(int a,int i,int j){
	for(k=i;k<=j-1;k++){
		if(cc[k]==a){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>dian[i];
	}
	for(int i=1;i<=n;i++){
		chushihua();
		for(int j=i;j<=n;j++){
			if(find(dian[j],i,j)==false){
				cc[j]=dian[j];
			}else{
				for(int p=k+1;p<=j-1;p++){
					cc[p]=0;
				}
			}
		}
		for(int j=i;j<=n;j++){
			ans[cc[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
