#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int s[N][35];
int k[35];
int sum3[N];
int n,m;
bool flag[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int t=a[i];
		int j=1;
		while(t!=0){
			s[i][j]=t%2;
			if(t%2==1){
				k[j]++;
			}
			t/=2;
			j++;
		}
		sum3[i]=j-1;
	}
	long long ans=0;
	bool flag2=false;
	for(int i=30;i>=1;i--){
		if(k[i]>=m&&!flag2){
			for(int j=1;j<=n;j++){
				if(s[j][i]==0){
					flag[j]=true;
				}
			}
			flag2=true;
		}
		if(flag2){
			int c=0;
			for(int j=1;j<=n;j++){
				if(s[j][i]==1&&flag[j]==false){
					c++;
				}
			}
			if(c>=m){
				ans+=pow(2,i-1);
				for(int j=1;j<=n;j++){
					if(s[j][i]==0){
						flag[j]=true;
					}
				}
			}
		}
	}
	printf("%lld",ans);

}
