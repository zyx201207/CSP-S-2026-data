#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
long long n,m,a[N]={0},l[N]={0},mx=0,cx=0;
bool flg=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[2]-a[1] != a[i]-a[i-1]){
			flg=0;
		}
	} 
	if(flg==1){
		cx=a[2]-a[1];
		mx=2*m;
		mx=sqrt(mx/cx);
		cout<<mx<<endl;
		return 0;
	}
	sort(a,a+n+1);
	for(int i=n;i>=1;i--){
		memset(l,0,sizeof(l));
		for(int j=1;j<=i;j++){
			l[j]=a[i]-a[j]+l[j-1];
		}
		for(int s=1;s<=i;s++){
			for(int t=s+mx;t<=i;t++){
				if(l[t]-l[s-1]<=m){
					mx=t-s+1;
				}
				else break;
			}
		}
	}	
	cout<<mx<<endl;
	return 0;
}
