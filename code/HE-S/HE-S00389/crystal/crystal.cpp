# include <bits/stdc++.h> 
# define ll long long
ll a[100005];
int main(){
	std::freopen("crystal.in", "r", stdin);
	std::freopen("crystal.out", "w", stdout);
	ll n, m;
	std::cin >> n >> m;
	for(int i=1; i<=n; i++) std::cin >> a[i];
	ll crys_count = 0, temp_count = 0;
	// crys_count 是总共的能量；temp_count 是相邻两颗水晶之差 */
    int count = 0;
	std::sort(a, a+n);
	for(int i=1; i<n; i++){
		temp_count = a[i+1] - a[i];
		if(temp_count*i + crys_count > m) break;
		crys_count += temp_count*i;
		count ++;
		// std::printf("%d %d\n", crys_count, temp_count);
	}
	std::cout << count+1;
	return 0;
}
