#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	
	
	//To:Ä³¸öOIer 
	//¿´T4´úÂë 
	
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m,cnt=0;
	long long ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	long long mid=1,may=1;
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		long long kll,llk;
		llk=b[i]*may;
		kll=cnt+llk;
		if(kll>m){
			while(true){
				cnt-=(b[i]-b[mid]);
				may--;
				mid++;
				kll=cnt+llk;
				if(kll<=m) break;
			}
		}
		cnt+=llk;
		may++;
		ans=max(may,ans);
	}
	cout<<ans;
	return 0;
}
