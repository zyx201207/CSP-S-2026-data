#include<bits/stdc++.h>
using namespace std;
long long int n,m,maxn=0,magic=0,i,sum;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long int a[n+1];
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=100001){
			magic++;
		}
		else{
			maxn=max(maxn,a[i]);
		}
	}
	sort(a+1,a+n+1);
	long long int p=a[1]-a[2];
	if(magic!=0){//特殊情况AB
		if(a[1]-a[2]==1){
			for(i=1;i<=n;i++){
				if(m-i>=0){
					sum++;
				}
				else{
					break;
				}
			}
			cout<<sum;
			return 0;
		}
		else{
			for(i=1;i<=n;i=i+p){
				if(m-i>=0){
					sum++;
				}
				else{
					break;
				}
			}
			cout<<sum;
			return 0;
		}
	}
	else{//正常
		long long int b[maxn+1];
		maxn=0;
		for(i=1;i<=n;i++){
			b[a[i]]++;
		}
		for(i=1;i<=n;i++){
			maxn=max(maxn,b[a[i]]);
		}
		m=m+a[1]-a[2];
		b[a[2]]++;
		for(i=2;i<=n;i++){
			long long int l=a[i+1]-a[i];
			l=l*b[a[i]];
			if(m-l>=0){
				sum+=b[a[i]];
			}
			else{
				break;
			}
			
		}
		cout<<max(maxn,sum);
		return 0;
	}

}
