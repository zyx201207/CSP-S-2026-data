#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N];
/*
vector<int> v[N];
int main(){
	cin >>n>>m;
	for(int i=1;i<=n;i++)cin >>a[i];
	for(int i=1;i<=n;i++){
		
	}
	return 0;
}

*/
int b[M],c[M];
int main(){
	
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >>n>>m;
	int ma=0,fl=0;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]<ma)fl=1;
	//	cout <<ma;
		ma=max(ma,a[i]);
	}
	if(fl==0){
		for(int i=1;i<=n;i++){
			b[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout <<b[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
			//	cout <<j<<endl;
				for(int k=b[a[j]];k<=j;k++)b[a[k]]=0;
			}
			b[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
			if(b[j]){
			//	cout <<" "<<j<<endl;
				c[j]++;
			}
	}
	for(int i=1;i<=m;i++)cout <<c[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
