#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n,m,a[222222],res[345678],card[345678],a_apr_cnts[345678];
bool a_apr[345678];
int ans[345678];
bool can_i_get_these_points;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	can_i_get_these_points=1;
	memset(a_apr_cnts,0,sizeof(a_apr_cnts));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!(a[i-1]<=a[i])){
			can_i_get_these_points=0;
		}
		a_apr_cnts[a[i]]++;
	}
	if(can_i_get_these_points){
		int res=0;
		for(int i=1;i<=m;i++){
			res=0;
			for(int j=i;j>=1;j--){
				res+=a_apr_cnts[j];
			}cout<<res<<" ";
		}
		
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(a_apr,0,sizeof(a_apr));
		for(int j=i;j<=n;j++){
			card[j]=a[j];
			if(a_apr[a[j]]){
				int l=j-1;
				while(l>=i && a[l]!=a[j]){
					a_apr[card[l]]=0;
					card[l]=0;
					l--;
				}
			}
			
			a_apr[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(a_apr[j])ans[j]++;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
