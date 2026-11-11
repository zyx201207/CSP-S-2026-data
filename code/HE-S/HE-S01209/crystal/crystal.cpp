#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long m;
bool al
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a1,a2;
	cin>>a1>>a2;
	for(int i=0;i<n;i++){
		if(a2-a1==1)m-=i;
		else m-=(a2-a1);
		if(m>0)cnt++;
		else{
			cout<<cnt;
			return 0;
		}
	}cout<<n;
	return 0;
}
//一道题都不会，我已急哭 
//希望这个特判可以给我分 
//希望明年能考好点吧 
