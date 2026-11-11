#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],b[5010][5010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			b[i][j]=a[i]-a[j];
		}
	}
	for(int i=1;i<=n;i++){
		long long num=m,cnt=0;
		for(int j=i;j>=1;j--){
			if(num-abs(b[i][j])>=0){
				num-=abs(b[i][j]);
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
