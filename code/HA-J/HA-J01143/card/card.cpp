#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int t=0,one,sum=0;
int cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	while(n--){
		int k;cin>>k;
		cnt[k]++;
		sum++; 
	}
	cout<<sum<<' ';
	for(int i=2;i<=m;i++){
		cout<<cnt[m]<<' ';
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
