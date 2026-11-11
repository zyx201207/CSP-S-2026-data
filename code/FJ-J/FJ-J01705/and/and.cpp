#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;

int n,m;
bool a[MAXN][32];
void push(int i,int x){
	string s;
	int k=1;
	while(x){
		a[i][k++]=x%2;
		x/=2;
	}
	return;
}
int sum[MAXN];
bool w[32];
void setsum(){
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=30;i++){
		for(int j=1;j<=n;j++){
			if(w[j]==1)
				sum[i]+=a[j][i];
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		push(i,x);
	}
	memset(w,1,sizeof(w));
	setsum();
	
	for(int i=30;i>=1;i--){
		if(sum[i]>=m){
			for(int j=1;j<=n;j++)
				if(a[j][i]==0) w[j]=0;
			setsum();
		}
	}

	int ans=0;
	for(int i=1;i<=30;i++){
		ans+=(sum[i]>=m)<<(i-1);
	}
	cout<<ans;
	return 0;
}
