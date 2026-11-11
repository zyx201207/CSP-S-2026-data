#include<bits/stdc++.h>
using namespace std;
long long n,m1,m,ans,sum,maxx=-1;
long long a[500005];
long long t[10005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,abs(a[i]));
	}
	if(maxx<=5005){
		for(int i=1;i<=n;i++){
			t[a[i]+5005]++;
		}
		for(int i=1;i<=10005;i++){
			if(t[i]){
				m=m1;
				for(int j=i;j>0;j--){
					if(t[j]){
						if(m-(t[j]*(i-j))>=0){
							m-=t[j]*(i-j);
							sum+=t[j];
						}
						else{
							sum+=m/(i-j);
							break;
						}
					}
				}
				ans=max(ans,sum);
				sum=0;
			}
		}
		cout<<ans;
	}
	else{
		cout<<n;
	}
	return 0;
}

