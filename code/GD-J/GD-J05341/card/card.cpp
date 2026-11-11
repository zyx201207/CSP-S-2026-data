#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ch=1,an[300005];
bool check(int d){
	for(int x=1;x<d;++x){
		if(a[x]==d){
			return false;
		}
	}
	return true;
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int len=0;
	for(int i=n-1;i>=1;--i){
		for(int j=n-i;j<=n;++j){
			int ans=0;
			if(check(a[j])){
				len++;
				b[len]=a[j];
			}else{
				len=0;
				for(int x=j-1;x>=1;--x){
					if(a[x]==a[j]){
						for(int d=1;d<=x;++d){
							len++;
							b[len]=a[d];
						}
					}
				}
			}
			for(int x=1;x<=len;++x){
				for(int d=1;d<=m;++d){
					if(b[x]==d&&an[d]==0){
						an[d]=i;
					}
				}
			}
		}
	}
	for(int i=m;i>=1;--i){
		cout<<an[i]<<" ";
	}
	return 0;
}
