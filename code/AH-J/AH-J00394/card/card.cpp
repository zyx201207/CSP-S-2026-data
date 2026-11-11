#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],c[300005],d[300005],e[300005],l;bool b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];  
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			l=0;
			for(int j=i;j<=n;j++){
				if(b[a[j]]==1){
					for(int k=d[a[j]]+1;k<=l;k++)b[c[k]]=0;
					l=d[a[j]];
				}
				else{
					c[++l]=a[j];b[a[j]]=1;d[a[j]]=l;
				}
			}
			for(int j=1;j<=5000;j++){
				if(b[j]==1)e[j]++;
				d[j]=0;b[j]=0;
			}
		}
	}
	else{
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				e[a[i-1]]=i-1;
				l=1;
			}
		}
	}
	for(int i=1;i<=m;i++)cout << e[i] << " ";
	return 0;
} 
