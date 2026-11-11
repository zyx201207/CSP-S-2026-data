#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[101010010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >>m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int maxn = 0;
	if(m == 2){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				maxn = max(maxn,a[i]&a[j]);
			}
		}
	}
	else if(m == 3){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				for(int k = j + 1;k < n;k++){
					maxn = max(maxn,a[i]&(a[j]&a[k]));
				}
			}
		}
	}
	else if(m == 4){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				for(int k = j + 1;k < n;k++){
					for(int l = k + 1;l < n;l++){
						maxn = max(maxn,a[i]&(a[j]&(a[k]&a[l])));
					}
				}
			}
		}
	}
	else if(m == 5){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				for(int k = j + 1;k < n;k++){
					for(int l = k + 1;l < n;l++){
						for(int o = l + 1;o < n;o++){
							maxn = max(maxn,a[i]&(a[j]&(a[k]&(a[l]&a[o]))));
						}
					}
				}
			}
		}
	}
	else if(m == 6){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				for(int k = j + 1;k < n;k++){
					for(int l = k + 1;l < n;l++){
						for(int o = l + 1;o < n;o++){
							for(int p = o + 1;p < n;p++){
								maxn = max(maxn,a[i]&(a[j]&(a[k]&(a[l]&(a[o]&a[p])))));
							}
						}
					}
				}
			}
		}
	}
	else if(m == 7){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				for(int k = j + 1;k < n;k++){
					for(int l = k + 1;l < n;l++){
						for(int o = l + 1;o < n;o++){
							for(int p = o + 1;p < n;p++){
								for(int q = p + 1;q < n;q++){
									maxn = max(maxn,a[i]&(a[j]&(a[k]&(a[l]&(a[o]&(a[p]&a[q]))))));
								}
							}
						}
					}
				}
			}
		}
	}
	else if(m == 8){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				for(int k = j + 1;k < n;k++){
					for(int l = k + 1;l < n;l++){
						for(int o = l + 1;o < n;o++){
							for(int p = o + 1;p < n;p++){
								for(int q = p + 1;q < n;q++){
									for(int r = q + 1;r < n;r++){
										maxn = max(maxn,a[i]&(a[j]&(a[k]&(a[l]&(a[o]&(a[p]&(a[q]&a[r])))))));
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if(m == 9){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				for(int k = j + 1;k < n;k++){
					for(int l = k + 1;l < n;l++){
						for(int o = l + 1;o < n;o++){
							for(int p = o + 1;p < n;p++){
								for(int q = p + 1;q < n;q++){
									for(int r = q + 1;r < n;r++){
										for(int s = r + 1;s < n;s++){
											maxn = max(maxn,a[i]&(a[j]&(a[k]&(a[l]&(a[o]&(a[p]&(a[q]&(a[r]&a[s]))))))));
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
	else if(m == 10){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				for(int k = j + 1;k < n;k++){
					for(int l = k + 1;l < n;l++){
						for(int o = l + 1;o < n;o++){
							for(int p = o + 1;p < n;p++){
								for(int q = p + 1;q < n;q++){
									for(int r = q + 1;r < n;r++){
										for(int s = r + 1;s < n;s++){
											for(int t = s + 1;t < n;t++){
												maxn = max(maxn,a[i]&(a[j]&(a[k]&(a[l]&(a[o]&(a[p]&(a[q]&(a[r]&(a[s]&a[t])))))))));
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
	cout << maxn;
	return 0;
}
