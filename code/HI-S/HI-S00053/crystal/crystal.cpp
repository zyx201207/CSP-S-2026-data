#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],x=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n>5000){
		long long w=a[2]-a[1];
		long long v=a[2]-a[1];
		while(m-v>=0){
			m-=v;
			v+=w;
			x++;
		}
		cout<<x;
		return 0;
	}
	else{
		for(int i=2;i<=n;i++){
			long long c=1;
			long long s=m;
			for(int j=i-1;j>=1;j--){
				int v=a[j];
				while(v<a[i]&&s>0){
					v++;
					s--;
				}
				if(v==a[i])c++;
				if(s==0||j==1){
					x=max(c,x);
					break;
				}
			}
			if(x>c)break;
		}
		cout<<x;
    }
	return 0;
}  
