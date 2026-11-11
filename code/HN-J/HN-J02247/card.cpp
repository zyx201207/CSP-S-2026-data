#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c=1,p[300010];
bool f[500010]={false};
int main(){
	freopen("card2.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j<=n;j++){
			b[a[j]]=c;
			if(f[a[j]]==true){
				f[a[j]]=false;
				for(int t=b[a[j]];t<=j;t++){
					f[a[t]]=false;
				}
			}else{
				f[a[j]]=true;
			}
			c++;
		}
		for(int t=1;t<=m;t++){
			if(f[t]==true){
				p[t]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout <<p[i] <<" ";
	}
	return 0;
} 
