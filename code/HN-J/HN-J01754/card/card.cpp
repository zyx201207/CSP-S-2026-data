#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],p[500010],s[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long ii=1;
		bool b=0;
		for(int j=0;j<=n;j++){
			p[j]=0;
		}
		for(int j=i-1;j<=n;j++){
			b=0;
			for(int k=1;k<=j-i+1;k++){
				if(p[k]==a[j]){
					for(int l=k;l<=j-i+1;l++){
						p[l]=0;
					}
					p[k]=a[j];
					ii=k;
					b=1;
					k=j;
				}
			}
			if(!b){
				p[ii]=a[j];
			}
			ii++;
		}
		for(int j=1;j<=ii;j++){
			s[p[j]]++;
		}
	}
	s[a[1]]--;
	for(int j=1;j<=m;j++){
		cout<<s[j]<<' ';
	}
	return 0;
}
