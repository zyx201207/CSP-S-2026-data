#include<bits/stdc++.h>
using namespace std;
bool A=1;
int a[500005],b[500005],c[500005],f[300005];
bool d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		cout<<1;
		return 0;
	}
	if(m==n){
		for(int i =1;i<=m;i++){
			cout<<1<<" ";
		}
		return 0;
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(a[i]<a[i-1]){
			A= 0;
		}
	}
	if(A==1){
		for(int i =1;i<=m;i++){
			cout<<1<<" ";
		}
		return 0;
	}
	for(int i =1;i<=n;i++){
		for(int j = i-1;j>=1;j--){
			if(d[i]==1){
				break;
			}
			if(a[i]==a[j]&&d[j] == 0){
				for(int o = j;o<i;o++){
					d[o] = 1;
					f[o] = i;
				}
				f[i] = i;
				break;
			}
		}
	}
	for(int i =1;i<=n;i++){
		if(d[i]==0){
			c[a[i]]++;
		}
	}
	int l = 2;
	while(l<=n){
		if(d[l]==1&&f[l]!=0){
			for(int i =l;i<=f[l];i++){
				c[a[i]]++;
				d[i]=1;
			}
		}
		for(int i =l;i<=n;i++){
			if(d[i]==0){
				c[a[i]]++;
			}
		}
		l++;
	}
	for(int i =1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
