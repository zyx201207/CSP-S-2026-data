#include<bits/stdc++.h>
using namespace std;
int a[500005]={},b[500005]={};
long long n,m;
void play(int x){
	int c[500005]={};
	int z=1,pd=0;
	c[1]=a[x];
	for(int i=x+1;i<=n;++i){
		pd=0;
		for(int j=1;j<=z;++j){
			if(c[j]==a[i]){
				z=j;
				pd=1;
			}
		}
		if(!pd){
			c[z+1]=a[i];
		    z++;
		}
	}
	for(int i=1;i<=z;++i){
//		cout<<c[i]<<" ";
		b[c[i]]++;
	}
//	cout<<endl;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int pd=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<a[i-1]){
			pd=0;
		}
	}
	if(pd){
		int mb=m;
		int da[300005]={};
		for(int i=n;i>=1;--i){
			if(a[i]==mb){
				da[mb]=i;
				mb--;
			}
		}
		for(int i=1;i<=m;++i){
			cout<<da[i]<<" ";
		}
//		for(int i=1;i<=m;++i){
//			int pd2=0;
//			for(int j=n;j>=1;--j){
//				if(a[j]==i){
//					cout<<j<<" ";
//					pd2=1;
//					break;
//				}
//			}
//			if(!pd2){
//				cout<<0<<" ";
//			}
//		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		play(i);
	}
	for(int i=1;i<=m;++i){
		cout<<b[i]<<" ";
	}
}
