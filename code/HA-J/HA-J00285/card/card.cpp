#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[50001]={0},b[30001]={0};
	for(int i=1;i<=n;i++) cin>>a[i];
	int s[50001]={0};
	for(int i=1;i<=n;i++){
		s[1]=a[i];s[2]=0;
		for(int j=i+1;j<=n;j++){
			bool f=0;
			int k;
			for(k=1;s[k]!=0;k++){
				if(s[k]==a[j]) s[k+1]=0,f=1;
			}
			if(!f) s[k+1]=a[j];
		}
		for(int j=1;s[j]!=0;j++){
			b[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
}
