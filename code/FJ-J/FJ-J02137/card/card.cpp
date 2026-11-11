#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,sum,m,s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		a[s]++;
	}
	for(int i=1;i<=m;i++){
		if(a[i]>=2){
			cout<<1<<" ";
			sum+=a[i];
		}
		else{
			cout<<sum+1<<" ";
			sum++;
		}
	}
	return 0;
}
