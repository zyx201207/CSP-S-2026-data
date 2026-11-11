#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n); 
	int ans=1;
	int i=1;
	while(m>0){
		if(a[i]==a[i+1]){
			ans++;
			i++;
		}
		int cha=a[i+1]-a[i];
		if(cha*i<=m){
			m=m-cha*i;
			ans++;
			i++;
		}
		else if(m<cha*i){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
