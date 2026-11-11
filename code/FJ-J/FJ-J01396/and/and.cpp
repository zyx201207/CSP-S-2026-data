#include<bits/stdc++.h>
using namespace std;
int a2[200010];
bool aa[200010][33];
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		a2[i]=t;
	}
	sort(a2,a2+n);
	int sum=1;
	for(int i=1;i<=n;i++){
		while(a2[i]>=2){
			aa[i][sum]=a2[i]%2;
			a2[i]/=2;
			sum++;
		}
		aa[i][sum]=1;
		aa[i][0]=sum;
	}
	int ans=0;
	for(int i=1;i<=n-m;i++){
		bool a[aa[i][0]];
		for(int j=1;j<=aa[i][0];j++){
			bool sam=true;
			for(int x=i;x<=i+m-1;x++){
				if(aa[x][j]!=1){
					sam=false;
					break;
				}
			}
			if(sam){
				a[j]=1;
			}else{
				a[j]=0;
			}
		}
		int ans1=0;
		for(int j=1;j<=sum;j++){
			int t=1;
			for(int x=1;x<j;x++){
				t*=2;
			}
			ans1+=t*a[j];
		}
		ans=max(ans,ans1);
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
