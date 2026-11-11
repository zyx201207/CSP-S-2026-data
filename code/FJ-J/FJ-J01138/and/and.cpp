#include<bits/stdc++.h>
using namespace std;
long long ans,shu[200001],maxx,dis[200001];
int n,m;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>shu[0];
	for(int i=1;i<n;i++){
		cin>>shu[i];
		maxx=max(maxx,shu[i]);
	}
	sort(shu,shu+n,cmp);
	int tmp=0;
	int cnt=n;
	for(int i=log(maxx);i>=0;i--){
		if(tmp==m){
			break;
		}
		for(int j=0;j<cnt;j++){
			if(shu[j]&(2^i)==1){
				tmp++;
				dis[tmp-1]=shu[j];
			}
			
		}
		if(tmp>=m){
			for(int j=0;j<tmp;j++){
				shu[j]=dis[j];
			}
			cnt=tmp;
		}
		tmp=0;
	}
	ans=shu[0];
	for(int i=1;i<m;i+=1){
		ans=ans&shu[i];
	}
	cout<<ans;
	return 0;
} 
