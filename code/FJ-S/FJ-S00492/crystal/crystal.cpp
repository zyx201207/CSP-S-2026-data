#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b,c,ans,d,e,f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b=m;
	while(1){
		for(int i=1;i<=n;i++){
			if(a[i]>a[1]){
				c=i-1;
				break;
			}
		}
		f=a[c+1]-a[c];
		if(b>=c){
			for(int i=f;i>=1;i--){
				if(b>=c*i){
					for(int j=1;j<=c;j++){
						a[j]+=i;
					}
					b-=c*i;
					break;
				}
			}
		}else{
			break;
		}
	}
	e=a[1];
	d=0;
	ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==e){
			d++;
		}else{
			ans=max(ans,d);
			d=1;
			e=a[i];
		}
	}
	cout<<ans;
	return 0;
}
