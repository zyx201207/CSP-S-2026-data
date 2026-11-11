#include<bits/stdc++.h>
using namespace std;
int n,m,a[6000001],maxn=0,maxx=0,minn=0x7ffffff;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}sort(a+1,a+n);
	for(int i=minn;i<=maxx;i++){
		int summ=0,s=m,g;
		for(int j=1;j<=n;j++){
			if(a[j]>i){
				g=j-1;
				break;
			}else if(a[j]==i){
				g=j;break;
			}
		}	
		for(int j=g;j>=1;j--){
			if(i-a[j]>s){
				break;
			}s-=i-a[j];summ++;
		}
		for(int j=g+1;j<=n;j++){
			if(a[j]==i){
				summ++;
			}
		}
		if(summ>=maxn){
			maxn=summ;
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
