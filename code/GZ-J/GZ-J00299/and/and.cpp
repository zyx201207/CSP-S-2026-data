//GZ-J00299,×ñÒåËÄÖĞ£¬Ô¬¼Îòà 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005],f=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int mx=a[1],ans=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		ans=(ans&a[i]);
	}
	int x=-1;
	if(m==1){
		cout<<mx;
	}else if(m==n){
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int o=(a[i]&a[j]);
				x=max(x,o);
			}
		}
		cout<<x;
	}else if(m==3&&n<=200){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					int o=(a[i]&a[j]&a[k]);
				    x=max(x,o);
				}
			}
		}
		cout<<x;
	}else if(m==4&&n<=100){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int l=k;l<=n;l++){
						int o=(a[i]&a[j]&a[k]&a[l]);
				        x=max(x,o);
					}
				}
			}
		}
		cout<<x;
	}else if(m==5&&n<=20){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int l=k;l<=n;l++){
						for(int p=l;p<=n;p++){
							int o=(a[i]&a[j]&a[k]&a[l]&a[p]);
				            x=max(x,o);
						}
					}
				}
			}
		}
		cout<<x;
	}else{
		sort(a+1,a+n+1);
		int q=a[n];
		for(int i=1;i<=m;i++){
			q=(q&a[n-i]);
		}
		cout<<q;
	}
	return 0;
}

