#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],maxx=0,ta[500010];
int check(int x,int i,int j){
	int flag=0;
	for(int k=i;k<j;k++){
		if(ta[k]==x) {
			flag=k;
			break;
		}
	}
	return flag;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ta[j]=a[j];
			int num=check(ta[j],i,j);
			if(num){
				for(int k=num;k<j;k++){
					ta[k]=0;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(ta[j]!=0) ans[ta[j]]++;
		}
	}
	for(int i=1;i<=maxx;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

