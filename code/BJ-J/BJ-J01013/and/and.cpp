#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool bin[N][30];
int fld[N]={0};
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		int cnt=0;
		while(x!=0){
			if(x%2==1)bin[i][cnt]=1;
			else bin[i][cnt]=0;
			cnt++;
			x/=2;
		}
	}
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!fld[j] && bin[j][i]==1) cnt++;
		}
		if(cnt<m) continue;
		else{
			for(int j=1;j<=n;j++){
				if(!fld[j] && bin[j][i]==0) fld[j]=1;
			}
		}
	}
	int ans=0x7fffffff;
	for(int j=1;j<=n;j++){
		if(!fld[j]) ans=ans&a[j];
	}
	cout<<ans;
	return 0;
}