#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int n,m; 
int a[N];
bool b[N];
bool sum[N][N];

void work(int i){
	int ans=0;
	for(int j=1;j<=m;j++) b[j]=0;
	
	int v[N]; for(int i=1;i<=n;i++) v[i]=0;
	int cnt=0;
	
	for(int j=i;j<=n;j++){
		for(int j=0;j<cnt;j++){
			//cout<<v[j]<<' ';
		}
		//cout<<' ';
		bool bh=0;
		for(int k=0;k<cnt;k++){
			if(v[k]==a[j]){
				bh=1;
			}
			
			if(bh==1){
				v[k]=0;
				cnt--;
			}
		}
		v[cnt]=a[j];
		cnt++;
	} 
	//cout<<"last ";
	for(int j=0;j<cnt;j++){
		//cout<<v[j]<<' ';
		sum[i][ (v[j]) ]=1;
	}
	//cout<<endl;
}

signed main(){
	
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		work(i);
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(sum[i][j]==1) ans++;
		}
		cout<<ans<<' ';
	}
	return 0;
} 
