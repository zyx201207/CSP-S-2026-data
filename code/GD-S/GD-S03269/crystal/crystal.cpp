#include <bits/stdc++.h>
using namespace std;
int n=0;
long long m=0;
vector<long long> k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	bool fb=1,fa=1;
	
	for(int i=0;i<n;i++){
		int tmp=0;
		cin>>tmp;
		k.push_back(tmp);
	}
	sort(k.begin(),k.end());
	//维护双指针l,r，当sum(l,r)+m>=(r-l+1)*r时，成立，记录最大的r-l+1 = ans; 
	int l=0,r=0;long long sum=k[0];
	long long ans=1;
	while(r<n){
		r++;
		sum+=k[r];
		if(sum+m>=(r-l+1)*k[r]) ans = max(ans,1ll*(r-l+1));
		else{
			while(sum+m < (r-l+1)*k[r]){
				sum-=k[l];
				l++;
			}
			ans = max(ans,1ll*(r-l+1));
		}

	}
	cout<<ans;
	return 0;
} 

