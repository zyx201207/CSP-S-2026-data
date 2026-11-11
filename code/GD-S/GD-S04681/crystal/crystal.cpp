#include<bits/stdc++.h>
using namespace std;

long long n,m,balance,cnt;
vector<long long> cry(500050);
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>cry[i];
	sort(cry.begin(),cry.end());
	balance=cry[n/2];
	for(long long i=0;i<n;i++){
		if(cry[i]==balance) cnt++;
		else{
			m-=balance-cry[i];
			if(m<0) break;
			else if(m==0){
				cnt++;
				break;
			}else cnt++;
		}
	}cout<<cnt;
	return 0;
}
