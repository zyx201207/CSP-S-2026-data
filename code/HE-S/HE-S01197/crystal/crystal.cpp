#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0,nn;
bool b=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n%2==0){
		nn=n/2;
	}else{
		nn=n/2+1;
	}
	while(1){
		for(int i=nn-1;i>=0;i--){
			if(a[i]==a[nn]){
				break;
			}
			else if(i==1&&a[i]==a[nn]){
				b==0;
				break;
			}
			else{
				if(m>=a[i]){
					m=m-(a[nn]-a[i]);
					a[i]=a[nn];
				}
				else{
					m=0;
					a[i]+=m;
				}
			}
		}
		if(m<=0||b==0){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[nn])ans++;
	}
	cout<<ans;
	return 0;
}
