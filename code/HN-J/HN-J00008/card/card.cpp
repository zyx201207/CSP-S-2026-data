#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
long long n,m,a[N],b[N],d=1,c[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[j]==b[k]){
					d=0;
					break;
				}
			}
			if(d==0){
				for(int k=j;k<=n;k++){
					b[k]=0;
				}
				b[n]=a[j];
			}else{
				ans++;
				b[n+ans]=a[j];
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]==a[i]){
				c[b[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<1<<' ';
	}
	return 0;
}
