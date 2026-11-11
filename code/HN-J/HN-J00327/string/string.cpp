#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

namespace solution{
	int n;
	int a[200005];
	char c[200005];
	int l,r;
	void main(){
		cin>>n;
		int sum = 0;
		for(int i = 1;i<=n;i++){
			cin>>a[i]>>c[i];
			sum+=a[i];
		}
		l = 1,r = n;
		int LL = 1,LR = a[1];
		int RL = sum-a[n]+1,RR = sum;
		int ans = 0;
		while(l<r){
			if(c[l]==c[r]){
				int lenA = LR-LL+1;
				int lenB = RR-RL+1;
				int delta = min(lenA,lenB);
//				ans+=delta;
				LL+=delta;
				RR-=delta;
				if(LL>LR){
					l++;
					LR+=a[l];
				}
				if(RL>RR){
					r--;
					RL-=a[r];
				}
			}else{
				int lenA = LR-LL+1;
				int lenB = RR-RL+1;
				int delta = min(lenA,lenB);
				ans+=delta;
				LL+=delta;
				RR-=delta;
				if(LL>LR){
					l++;
					LR+=a[l];
				}
				if(RL>RR){
					r--;
					RL-=a[r];
				}
			}
		}
		cout<<ans;
	}
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solution::main();
	return 0;
}

