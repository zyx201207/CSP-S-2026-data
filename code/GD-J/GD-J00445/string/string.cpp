#include<bits/stdc++.h>
using namespace std;
char S[200000005];
#define ll long long
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int samem=0;
	char sam;
	int n,i=0;
	cin>>n;
	while(n--){
		int x;
		char y;
		cin>>x>>y;
		if(sam!=y){
			samem^=1;
		}
		sam=y;
		if(i+x>2000000005){
			continue;
		}
		for(int j=i;j<i+x;j++){
			S[j]=y;
		}
		i+=x;
	}
	if(samem){
		cout<<0;
		return 0;
	}
	int L=i;
	for(int i=0;i*2<L;i++){
		if(S[i]!=S[L-1-i]){
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
