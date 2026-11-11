#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+10;
long long a[N],mj;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			mj=max(mj,a[i]);
		}
		cout<<mj;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&a[i]==a[j]){
					mj=max(mj,a[i]);
				}
			}
		}
		cout<<mj;
	}
	return 0;
} 
