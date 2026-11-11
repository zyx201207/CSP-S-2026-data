#include<iostream>
using namespace std;
int cnt[200503];
int pre[200050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(int i=1;i<=m;i++){
		pre[i]=pre[i-1]+cnt[i];
	}
	for(int i=1;i<=m;i++){
		if(cnt[i]%2==1){
			cout<<pre[i-1]+cnt[i]/2+1<<' '; 
		}else{
			cout<<pre[i-1]+cnt[i]/2<<' ';
		}
	}
	return 0;
} 
