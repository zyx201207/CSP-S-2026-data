#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[1000010],cnt[1000010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	LL sum=0;
	for(int i=1;i<=300010;i++){
		if(cnt[i]!=0){
			sum+=cnt[i];
			cout<<sum<<" ";
		}
	}
	return 0;
}
