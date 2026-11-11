#include<bits/stdc++.h>
#define int long long
#define endl '/n'
using namespace std;
long long num[200005];
string zm[200005];
signed main(){
	//freopen(string.in,"r",stdin);
	//freopen(string.out,"w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n;
	long long lenl = 0;
	cin>>n;
	
	vector<string>l;
	for(long long i = 0;i < n;i++){
		cin>>num[i]>>zm[i];
	}
	
	for(long long i = 0;i < n;i++){
		lenl += num[i];
		for(long long j = 0;j < num[i];j++){
			l.push_back(zm[i]);
		}
	}
	long long ans = 0;
	if(lenl % 2 == 0){
		for(long long i = 0;i <= lenl / 2 - 1;i++){
			long long j = lenl  - 1 - i;
			if(l[i] != l[j]){
				ans++;
			}
			
		}
	}	
	
	if(lenl % 2 == 1){
		for(long long i = 0;i <= lenl / 2 - 1;i++){
			long long j = lenl  - 1 - i;
			if(l[i] != l[j]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
