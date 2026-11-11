#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500002],x[500002],top[500002],ans,ss=1;
bool f[500002],ff=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])ff=0;
	}
	if(ff){
		for(int i=1;i<=m;i++){
			int g=i;
			for(int j=ss;j<=n;j++){
				if(g==a[j])ans++;
				else{
					cout<<ans<<' ';
					ss=j;
					break;
				}
			}
		}
		cout<<ans<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)x[j]=0;
		for(int j=i;j<=n;j++)x[j]=a[j];
		for(int j=i;j<=n;j++){
			if(!f[x[j]])f[x[j]]=1;
			else{
				bool v=0;
				for(int k=i;k<=j;k++){
					if(v){
						x[k]=0;
						f[x[k]]=0;
					}
					if(x[k]==x[j])v=1;
				}
			}
		}
		for(int j=1;j<=m;j++)for(int k=1;k<=n;k++){
			if(x[k]==j)top[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<top[i]<<' ';
	return 0;
}

