#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005],c[1000005];
bool f=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int t=1;
	while(t<=n){
		for(int i=1;i<=n;i++) b[i]=0;
		f=true;
		for(int i=t;i<=n;i++){
			f=true;
			b[i]=a[i];
			for(int j=t;j<i;j++){
				if(f=false) continue;
				if(b[j]==a[i]){
					for(int k=j;k<=i-1;k++){
						b[k]=0;
					}
					f=false;
				}
			}
		}
		for(int k=t;k<=n;k++){
				c[b[k]]++;
		}
		t++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

