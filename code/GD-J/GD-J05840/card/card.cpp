#include<bits/stdc++.h>
using namespace std;
struct Zack{
	bool pa;
	long long sit;
};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],ans[n+1];
	Zack p[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=0;
		p[i].pa=false;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(p[a[j]].pa)
				for(int c=p[a[j]].sit;c<=j;c++)
					p[a[c]].pa=false;
			p[a[j]].pa=true;
			p[a[j]].sit=j;
		}
		for(int f=1;f<=m;f++)
			if(p[a[f]].pa){
				ans[f]++;
				p[a[f]].pa=false;
			}
	}
	for(int i=1;i<=m;i++)
		if(a[i]!=0)
			cout<<ans[i]<<' ';
	return 0;
}
