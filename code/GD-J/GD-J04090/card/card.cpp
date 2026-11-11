#include<bits/stdc++.h>
using namespace std;
int n,m,pai[100005],cnt1,cnt2;
bool all=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pai[i];
		if(i==1) continue;
		if(pai[i]!=pai[i-1]) all=0;
	}
	if(all){
		for(int i=1;i<=n;i++) cout<<pai[1];
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(pai[i]==pai[n]&&pai[i]==1) cnt1++;
		else if(pai[i]==pai[n]&&pai[i]==2) cnt2++;
		else cnt1++,cnt2++;
	}
	cout<<cnt1<<" "<<cnt2;
	return 0;
}
