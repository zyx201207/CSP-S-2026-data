#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e3+10;
int a[N];
int d[N][N];
int er(int wlw,int lsy){
    if(wlw==lsy)return lsy;
    long long f=1;
    int ans=0;
    while(lsy>=1&&wlw>=1){
    	if(lsy%2==1&&wlw%2==1)ans+=f;
    	f*=2;
    	lsy/=2;
    	wlw/=2;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i][1]=max(d[i-1][1],a[i]);
	}
	for(int i=2;i<=m;i++){
		d[i][i]=er(d[i-1][i-1],a[i]);
	}
	for(int i=3;i<=n;i++){
		for(int j=2;j<i;j++){
			d[i][j]=max(d[i-1][j],er(d[i-1][j-1],a[i]));
		}
	}
	cout<<d[n][m];
} 
