#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10000001],max1 = 0,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	long long s = m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		sort(a + 1,a + n + 1);
		cout << a[n];
		return 0;
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(a[i] & a[j] > max1){
					max1 = a[i] & a[j];
				}
			}
		}
		cout << max1;
		return 0;
	}
	if(m == 3){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					ans = a[i];
					ans &= a[j];
					ans &= a[k];
					if(ans > max1){
						max1 = ans;
					}
				}
			}
		}
		cout << max1;
		return 0;
	}
	if(m == 4){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int l = k + 1;l <= n;l++){
						ans = a[i];
						ans &= a[j];
						ans &= a[k];
						ans &= a[l];
						if(ans > max1){
							max1 = ans;
						}
					}
				}
			}
		}
		cout << max1;
		return 0;
	}
	if(m == 5){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int l = k + 1;l <= n;l++){
						for(int x = l + 1;x <= n;x++){
							ans = a[i];
							ans &= a[j];
							ans &= a[k];
							ans &= a[l];
							ans &= a[x];
							if(ans > max1){
								max1 = ans;
							}
						}
					}
				}
			}
		}
		cout << max1;
		return 0;
	}
	if(m == 6){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int l = k + 1;l <= n;l++){
						for(int x = l + 1;x <= n;x++){
							for(int y = x + 1;y <= n;y++){
								ans = a[i];
								ans &= a[j];
								ans &= a[k];
								ans &= a[l];
								ans &= a[x];
								ans &= a[y];
								if(ans > max1){
									max1 = ans;
								}
							}
						}
					}
				}
			}
		}
		cout << max1;
		return 0;
	}
	if(m == 7){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int l = k + 1;l <= n;l++){
						for(int x = l + 1;x <= n;x++){
							for(int y = x + 1;y <= n;y++){
								for(int z = y + 1;z <= n;z++){
									ans = a[i];
									ans &= a[j];
									ans &= a[k];
									ans &= a[l];
									ans &= a[x];
									ans &= a[y];
									ans &= a[z];
									if(ans > max1){
										max1 = ans;
									}
								}
							}
						}
					}
				}
			}
		}
		cout << max1;
		return 0;
	}
	if(m == 8){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int l = k + 1;l <= n;l++){
						for(int x = l + 1;x <= n;x++){
							for(int y = x + 1;y <= n;y++){
								for(int z = y + 1;z <= n;z++){
									for(int b = z + 1;b <= n;b++){
										ans = a[i];
										ans &= a[j];
										ans &= a[k];
										ans &= a[l];
										ans &= a[x];
										ans &= a[y];
										ans &= a[z];
										ans &= a[b];
										if(ans > max1){
											max1 = ans;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << max1;
		return 0;
	}
	if(m == 9){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int l = k + 1;l <= n;l++){
						for(int x = l + 1;x <= n;x++){
							for(int y = x + 1;y <= n;y++){
								for(int z = y + 1;z <= n;z++){
									for(int b = z + 1;b <= n;b++){
										for(int c = b + 1;c <= n;c++){
											ans = a[i];
											ans &= a[j];
											ans &= a[k];
											ans &= a[l];
											ans &= a[x];
											ans &= a[y];
											ans &= a[z];
											ans &= a[b];
											ans &= a[c];
											if(ans > max1){
												max1 = ans;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << max1;
		return 0;
	}
	if(m == 10){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int l = k + 1;l <= n;l++){
						for(int x = l + 1;x <= n;x++){
							for(int y = x + 1;y <= n;y++){
								for(int z = y + 1;z <= n;z++){
									for(int b = z + 1;b <= n;b++){
										for(int c = b + 1;c <= n;c++){
											for(int d = c + 1;d <= n;d++){
												ans = a[i];
												ans &= a[j];
												ans &= a[k];
												ans &= a[l];
												ans &= a[x];
												ans &= a[y];
												ans &= a[z];
												ans &= a[b];
												ans &= a[c];
												ans &= a[d];
												if(ans > max1){
													max1 = ans;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << max1;
		return 0;
	}
	if(m == n){
		ans = a[1];
		for(int i = 2;i <= n;i++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	return 0;
} 
