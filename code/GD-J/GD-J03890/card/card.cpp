#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n=0,t=0,m=0,st,en;
	cin>>n>>m;
	bool a1[30005]={};
	int a2[50005]={};
	int t1[30005]={};
	int x=0;

	for(int i=1;i<=n;i++){
		cin>>x;
		if(a1[x]==1){
			for(int j=t-1;j>=1;j--){
				if(a2[j]==x){	
					st=j;
					en=t;
					t=j;
					break;
				}
			}
			for(int j=st;j<=en;j++){
				a1[a2[j]]==0;
			}
			t-=1;
		}
		t++;
		a2[t]=x;
		a1[x]=1;
		
		for(int r=1;r<=m;r++){
			if(a1[r]==1){
				t1[r]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t1[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
