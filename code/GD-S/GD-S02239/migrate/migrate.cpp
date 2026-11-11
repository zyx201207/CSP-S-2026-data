#include<bits/stdc++.h>
using namespace std;
int zuo[1000005]={0};
bool found(int i,int u,int is[1000005],int d){//寻找区间内最小值 
	int len[1000005]={0};
	len[i]=1;
	int wei[1000005]={0};
	int ji=0;
	for(int j=i+1;j<u;j++){
		 len[j]=len[j-1]+1;
		 wei[j]++;
		for(int q=j;is[i]-is[q]>=d;){
			if(j==u&&len[q]!=0){
				len[j]=min(len[j],len[q]);
				wei[len[j]]++;
				ji=j;
			}
		}
	}
	if(wei[len[ji]]==2){
		return true;
	}
	else{
		return false;
	}
}
//insland is[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c=0,t=0;
	cin>>c>>t;
	int n=0,d=0;
	for(int oo=0;oo<t;oo++){
		cin>>n>>d;
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>zuo[i];
		}
		for(int v=0;v<n-1;v++){
			for(int u=v+1;u<n-1;u++){
				if(found(v,u,zuo,d)==true){
					ans++;
				}
			}
		}	
		cout<<ans;
	} 
	return 0;
	fclose(stdin);
	fclose(stdout);
}
