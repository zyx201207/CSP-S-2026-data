#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
long long b[500010],c[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int bb=1;
	for(int i=1;i<=n;i++){//µÚ¼¸¾Ö 
		b[1]=i;
		for(int j=i+1;j<=n;j++){
			bool f=0;
			for(int k=1;k<=bb;k++){
				if(a[j]==b[k]){
					bb=k;
					f=1;
				}
				continue;
			}
			if(!f)b[++bb]=a[j];
		}
		int ans=0;
		for(int o=1;o<=bb;o++){
			for(int p=1;p<=m;p++){
				if(b[o]=p)c[p]++;
				continue;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
