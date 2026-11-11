#include<bits/stdc++.h>
using namespace std;
bool t[200005][35];
bool f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,x,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		int b=1;
		while(x){
			t[i][b++]=x%2;
			x/=2;
		}
	}
	long long now=1,sum=0;
	for(int i=2;i<=30;i++){
		now*=2;
	}
	for(int i=30;i>=1;i--){
		int fl=0;
		for(int j=1;j<=n;j++){
			if(!f[j])fl+=t[j][i];
		}
		if(fl>=m){
			sum+=now;
			for(int j=1;j<=n;j++){
				if(!t[j][i]&&!f[j])f[j]=1;
			}
		}
		now/=2;
	}
	cout<<sum;
	return 0;
}//2147483648
