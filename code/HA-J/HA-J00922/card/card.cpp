#include<bits/stdc++.h> 
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m,a[500005],b[500005],c[500005],cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int p=n; 
	while(p>0){
		int win=0;
		win++;
		cnt=1;
		p--;
		int x[500005];
		for(int i=n-p;i<=n;i++){
			b[cnt]=a[i];
			cnt++;
		}
		for(int i=1;i<=cnt;i++){
			int q=b[i];
			if(x[q]==1){
				int l=cnt-1;
				while(b[l]!=b[i]){
					x[b[l]]--;
					m--;
				}
			}else{
				x[q]++;
			}
		}
		if(x[win]>0){
			c[win]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i];
	}
	return 0;
}
