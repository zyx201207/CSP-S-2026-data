#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans=1,l;
long long a[6000000];
int main(){
	freopen ("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(a[i]-a[i-1]==1){
			cnt++;
		}
	}
	
	if(cnt==n){
		while(m>0&&m>=l){
			
			
			if(l==n){
				cout<<n<<endl;
				return 0;
			}
			l++;
			m-=l;
			ans++;
		}
	}
	else{
		sort(1+a,a+1+n);
		for(int i=1;i<=n;i++){
			
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 4
1 2 3 4 5
*/
