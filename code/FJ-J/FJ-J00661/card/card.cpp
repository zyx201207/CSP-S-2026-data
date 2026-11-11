#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],d[500000],idx;
struct nb{
	int num,use=0;
}ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int flag=0;
			for(int k=0;k<idx;k++){
				if(d[k]==a[j]){
					flag=1;
					break;
				}
			}
			while(flag){
				if(d[idx-1]==a[j]){
					d[idx--]=0;
					break;
				}
				d[idx--]=0;
			}
			d[idx++]=a[j];
		}
		for(int j=0;j<idx;j++){
			for(int k=1;k<=m;k++){
				if(d[j]==k&&ans[k].use!=i){
					ans[k].num++;
					ans[k].use=i;
					break;
				}
			}
			
			d[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i].num<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
