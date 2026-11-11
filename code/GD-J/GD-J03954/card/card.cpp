#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	if(n<=5&&m<=2){
		if(m==1){
			cout<<n<<'\n';
		}else{
			
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		sum+=cnt[i];
		cout<<sum<<" ";
	}
	return 0;
} 
