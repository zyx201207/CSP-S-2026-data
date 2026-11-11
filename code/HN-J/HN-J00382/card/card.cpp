#include<bits/stdc++.h>
using namespace std;
int a[300005],point[300005],sum[300005];
int m,n;
void numput(int k){
	for(int i=k;i<=m;i++){
		if(point[a[i]]==0){
			point[a[i]]=i;
		}
		else{
			int p=point[a[i]];
			for(int q=0;q<i;q++){
				if(point[q]>=p&&point[q]<i){
					point[q]=0;
				}
			}
			point[a[i]]=i;
		}
	}
	for(int i=1;i<=n+1;i++){
		if(point[i]!=0){
			sum[i]++;
			point[i]=0;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		numput(i);
	}
	for(int i=1;i<=n;i++){
		cout<<sum[i]<<' ';
	}
	fclose(stdin);fclose(stdout);
	return 0;
}


