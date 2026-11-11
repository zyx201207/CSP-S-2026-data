#include<iostream>
using namespace std;
int n,m;
int a[200010];
int b[200010][35];
int nx[200010][35];
long long ans=0;
int mb=0;
long long gtv(int e){
	long long r=1;
	for(int i=1;i<=e;i++)r*=2;
	return r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],j=0;
		while(x){
			b[i][j]=x%2;
			x/=2;
			mb=max(mb,j);
			++j;
		}
	}
	for(int i=1;i<=n;i++){
		nx[i][33]=1;
	}
	int cnt,k=33;
	
	for(int i=mb;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(!nx[j][k])continue;
			if(b[j][i])
			{
				cnt++;
				nx[j][i]=1;
			}
		}
		if(cnt>=m){
			ans+=gtv(i);
			k=i;
		}
	}
	cout<<ans;
	return 0;
}
