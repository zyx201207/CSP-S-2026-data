#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],f[M],b[M],c[M],s[M];
bool st[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		b[a[i-1]]--;
		for(int j=1;j<=n;j++){
			st[j]=0;
		}
		for(int j=1;j<=m;j++){
			c[j]=b[j];
			f[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				f[a[j]]=j;
			}else{
				for(int l=f[a[j]];l<j;l++){
					if(st[l]){
						continue;
					}else{
						st[l]=1;
						c[a[l]]--;
					}
				}
				f[a[j]]=0;
			}
		}
		for(int j=1;j<=m;j++){
			if(c[j]>0){
				s[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
