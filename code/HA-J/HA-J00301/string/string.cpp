#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 7;
//172.16.12.5
char aa[N];
int arr[N];
int n;
string final;
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n;
	for(int i = 1;i<=n;++i){
		cin>>arr[i]>>aa[i];
//		mp[aa[i]] += arr[i];
//		tot += mp[aa[i]];
//		MIN = min(MIN,arr[i]);
		for(int i1 = 1;i1<=arr[i];i1++){
			final += aa[i];
		}
	}
//	cout<<final<<endl;
	int ans1 = 0;
	for(int i = 0,j = final.length() - 1;j>=final.length()+1>>1,i<final.length() + 1>>1;++i,--j){
			if(final[i]!=final[j]){
				ans1++;
				continue;
			}
//		}
	}
	cout<<ans1<<endl;

}