#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
int n,num,ans;
long long m,ai,sum;
std::vector<long long> a;
std::unordered_map<long long,int> cnt;
void init(){
	scanf("%d%lld",&n,&m);
	while(n--){
		scanf("%lld",&ai);
		if(cnt[ai]==0) a.push_back(ai);
		cnt[ai]++;
	}
	a.push_back(-1e13);
	std::sort(a.begin(),a.end());
}
void process(){
	for(int l=1,r=1;r<(int)a.size();r++){
		sum+=num*(a[r]-a[r-1]);
		num+=cnt[a[r]];
		while(sum>m){
			sum-=(a[r]-a[l])*cnt[a[l]];
			num-=cnt[a[l]];
			l++;
		}
		cnt[a[l-1]]=(m-sum)/(a[r]-a[l-1]);
		if(cnt[a[l-1]]!=0){
			l--;
			sum+=cnt[a[l]]*(a[r]-a[l]);
			num+=cnt[a[l]];
		}
		ans=std::max(ans,num);
	}
}
void print(){
	printf("%d",ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init();
	process();
	print();
	return 0;
}
