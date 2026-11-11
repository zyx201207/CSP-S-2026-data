#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool arr[300000][32]={};
	int lon[300000]={};
	int sl[32]={};
	int n,m,kin=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long a;
		cin>>a;
		int k=1;
		while(a>0){
			arr[i][k]=a%2;
			if(arr[i][k]==1){
				sl[k]++;
			}
			a=a/2;
			k++;
		}
		lon[i]=k-1;
		kin=max(kin,lon[i]);
	}
	int ans=0;
	int d=n;
	for(int i=kin;i>=1;i--){//位数 
		if(sl[i]<m)continue;
		ans+=pow(2,i-1);
		for(int j=0;j<n;j++){//每个数 
			if(arr[j][0]==1)continue;
			if(arr[j][i]!=1){//淘汰 
				d--;
				if(d<m){
					cout<<ans;
					return 0;
				}
				arr[j][0]=1;
				for(int w=1;w<=lon[j];w++){
					if(arr[j][w]==1)sl[w]--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
