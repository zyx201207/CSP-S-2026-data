#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	long long n, m;
	std::cin >> n >> m;
	
	std::vector<long long> crystals(n+1);
	for(long long i=1;i<=n;i++){
		long long a;
		std::cin >> a;
		crystals[i] = a;
	}
	
	std::sort(crystals.begin(),crystals.end());
	
	std::vector<long long> diff(n+1);
	for(long long i=2;i<=n;i++){
		diff[i]=crystals[i]-crystals[i-1];
	}
	
	std::vector<long long> diff_sum(n+1,0);
	diff_sum[1]=diff[1];
	for(long long i=2;i<=n;i++){
		diff_sum[i]=diff_sum[i-1]+diff[i];
	}
	
	long long ans = 1;
	long long cur_spent = 0;
	long long l=1;
	for(long long r=2;r<=n;r++){
		cur_spent += diff[r]*(r-l);
		// std::cout << "[Debug Message][Outside for] l=" <<l<< ", r=" <<r<< ", ans="<<ans<<", cur_spent="<<cur_spent<<std::endl;
		if(cur_spent > m){
			while(cur_spent>m){
				// std::cout << "[Debug Message][Inside While] l = " << l <<" + 1 = " << l+1 << std::endl;
				if(++l>r){
					goto out_continue;
				}
				// std::cout << "[Debug Message] cur_spent: "<< cur_spent<<" -> " << cur_spent-(diff_sum[r]-diff_sum[l]) << std::endl;				
				cur_spent -= (diff_sum[r]-diff_sum[l]);
			}
		}
		// std::cout << "[Debug Message] ans: "<< ans<<" -> " <<std::max(r-l+1,ans) << std::endl;
		ans = std::max(r-l+1,ans);
		out_continue:
			continue;
	}
	
	std::cout << ans << "\n";
	
	return 0;
} 
