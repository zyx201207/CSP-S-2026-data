#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10 ; 
int a[N],las[N],ans[N],q[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int cnt=1;
	for(int i=1;i<=n;i++){
		memset (q,0,sizeof(q));
		memset (las,0,sizeof(las));
		for(int j=i;j<=n;j++){
			q[j]=a[j];
			if(las[a[j]]){
			//	cout<<cnt++<<':'; 
				for(int k=las[a[j]];k<j;k++){
					q[k]=0;
					las[a[k]]=0;
				}
			}
			las[a[j]]=j;
		//	cout<<q[j]<<' ';
		}//cout<<i<<endl;
		for(int j=1;j<=n;j++){
			//cout<<q[j]<<' ';
			if(q[j]){
				ans[q[j]]++;
			}//cout<<j<<':'<<q[j]<<endl;
	}
	//	ans+=num[i][j];
	}
		for(int j=1;j<=m;j++){
			cout<<ans[j]<<' ';
		}
	//cout<<999;
	return 0;
	
} 
