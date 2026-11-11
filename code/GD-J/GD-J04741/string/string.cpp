#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],ans;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],m+=a[i];
	for(int i=1,j=n,idx1=1,idx2=m;idx1*2<=m;i++){
		idx1+=a[i];
		while(idx2>m-idx1+1){
			if(idx2-a[j]>m-idx1+1){
				if(c[j]!=c[i])ans+=a[j];
				idx2-=a[j--];
			}
			else{
				int dif=idx2-m+idx1-1;
				if(c[j]!=c[i])ans+=dif;
				idx2-=dif,a[j]-=dif; 
			}
		}
	}
	cout<<ans;
	return 0;
}
