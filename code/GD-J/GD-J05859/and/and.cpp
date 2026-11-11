#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans,n,m,cnt;
bool f[500005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(((a[j]>>i)&1)&&!f[j]){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=1<<i;
			for(int j=1;j<=n;j++){
				if(!((a[j]>>i)&1)){
					f[j]=1;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
