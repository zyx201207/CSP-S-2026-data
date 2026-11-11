#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	int time[m]={};
	for(int i=0;i<m;i++){
		cin>>time[i];
	}
	
//	int a[500]={},t[500]={};
//	for(int i=0;i<n;i++){
//		int k;
//		cin>>k;
//		for(int j=0;j<k*2;j++){
//			cin>>a[j]>>t[j];
//		}
//	}
//	
//	for(int i=0;i<q;i++){
//		int x,y;
//		cin>>x>>y;
//		cout<<time[y]+t[x];
//	}

//	int at[50][50]={};
//	for(int i=0;i<n;i++){
//		int k;
//		cin>>k;
//		for(int j=0;j<k*2;j++){
//			cin>>at[i][j];
//		}
//	}
//	
//	int x,y;
//	for(int i=0;i<q;i++){
//		for(int j=0;j<2;j++){
//			cin>>x>>y;
//		}
//	}
	
	for(int i=0;i<q;i++){
		int sum=0;
		for(int d:time)sum+=d;
		cout<<sum<<"\n";
	}

	return 0;
}
