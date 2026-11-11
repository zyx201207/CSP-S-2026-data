#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,d[200001]={},t[200001]={},c[200001]={},ans[200001]={};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	for(int i=1;i<=n;i++){
		int p=0;
		for(int j=i-1;j<n;j++){
			if(c[d[j]]){
				while(t[p]!=d[j]){
					p--;
					c[t[p]]=0;
				}
				c[d[j]]=0;
			}
			t[p]=d[j];
			p++;
			c[d[j]]++;
		}
		for(int j=0;j<=m;j++){
			ans[j]+=c[j];
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
