#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],h[300005],p[300005],cnt;
bool used[300005];
inline int read(){
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		ch=getchar();
	}
	int s=0;
	while(ch>='0' && ch<='9'){
		s=s*10+ch-48;
		ch=getchar();
	}
	return s;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			memset(used,0,sizeof(used));
			memset(p,0,sizeof(p));
			cnt=0;
			for(int j=i;j<=n;j++){
				if(used[a[j]]==0){
					used[a[j]]=1;
					p[++cnt]=a[j];
				}
				else {
					for(int k=1;k<=cnt;k++){
						if(p[k]==a[j]){
							int x=0;
							for(int l=k;l<=cnt;l++){
								p[l]=0;
								x++;
							}
							cnt-=x;
							break;
						}
					}
					used[a[j]]=1;
					p[++cnt]=a[j];
				}
			}
			for(int j=1;j<=m;j++){
				h[p[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<h[i]<<" ";
		}
	}
	else {
		for(int i=1;i<=n;i++){
			memset(used,0,sizeof(used));
			for(int j=i;j<=n;j++){
				if(used[a[j]]==0){
					h[a[j]]++;
					used[a[j]]=1;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<h[i]<<" ";
		}
	}
}
