//GZ-J00651 兴义市弘毅中学  韦杰
#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[200010];

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=(1<<n);i++){
		int cut=0,sum;
		bool f=0;
		for(int j=0;j<=n;j++){
			if(i&(1<<j)){
				cut++;
			}
		}
		if(cut==m){
			for(int j=0;j<=n;j++){
				if(i&(1<<j)){
					if(f==0){
						sum=a[j];
						f=1;
					}
					else{
						sum=sum&a[j];
					}
				}
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
