#include<bits/stdc++.h>
using namespace std;
int a[500005],t[300005];
bool xz[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool xza=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(xza==true){
			if(xz[a[i]]==true){
				xza=false;
				continue;
			}
			xz[a[i]]=true;
		}
	}
	if(xza==true){
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int b[n+5];
		int cnt=0;
		for(int j=i;j<=n;j++){
			bool cmp=false;
			for(int m=1;m<=cnt;m++){
				if(cmp==true){
					b[m]=0;
					cnt--;
					continue;
				}
				if(b[m]==a[cnt+1]){
					cmp=true;
				}
			}
			cnt++;
			b[cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++){
			t[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
