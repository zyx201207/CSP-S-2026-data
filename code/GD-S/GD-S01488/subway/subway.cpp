#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int INT=1e9;
int w[N],zhantai[N],t[N];
int a[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int z=1;z<=2*k;z+=2){
		cin>>zhantai[z];
	} 
	for(int j=2;j<=2*k;j++){
		cin>>t[j];
	}
	int x,y;
	cin>>x>>y;
	int sum=0,minn=-INT;
	for(int i=1;i<=k;i++){
		if(zhantai[i]==zhantai[1]){
			sum+=w[1];
		}
		for(int j=1;j<=k;j++){
			sum+=a[i][j];
		}
		minn=min(sum,minn);
	}
	cout<<minn<<endl;
	return 0;
}
