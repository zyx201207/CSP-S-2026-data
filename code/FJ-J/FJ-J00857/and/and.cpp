#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[200010], maxx = -1;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			maxx = max(maxx, a[i]);
		}
	} else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				maxx = max(maxx, (a[i] & a[j]));
			}
		}
	} else if (m == 3) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					maxx = max(maxx, (a[i] & a[j] & a[k]));
				}
			}
		}
	} else if (m == 4) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) {
						maxx = max(maxx, (a[i] & a[j] & a[k] & a[l]));
					}
				}
			}
		}
	} else if (m == 5) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) {
						for (int m = l + 1; m <= n; m++) {
							maxx = max(maxx, (a[i] & a[j] & a[k] & a[l] & a[m]));
						}		
					}
				}
			}
		}
	} else if (m == 6) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) {
						for (int m = l + 1; m <= n; m++) {
							for (int o = m + 1; o <= n; o++) {
								maxx = max(maxx, (a[i] & a[j] & a[k] & a[l] & a[m] & a[o]));
							}	
						}	
					}
				}
			}
		}
	} else if (m == n) {
		maxx = a[1];
		for (int i = 2; i <= n; i++) {
			maxx &= a[i];
		}
	} else if (m == 7) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) {
						for (int m = l + 1; m <= n; m++) {
							for (int o = m + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									maxx = max(maxx, (a[i] & a[j] & a[k] & a[l] & a[m] & a[o] & a[p]));
								}	
							}	
						}	
					}
				}
			}
		}
	} else if (m == 8) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) {
						for (int m = l + 1; m <= n; m++) {
							for (int o = m + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										maxx = max(maxx, (a[i] & a[j] & a[k] & a[l] & a[m] & a[o] & a[p] & a[q]));
									}
								}	
							}	
						}	
					}
				}
			}
		}
	} else if (m == 9) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) {
						for (int m = l + 1; m <= n; m++) {
							for (int o = m + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										for (int r = q + 1; r <= n; r++) {
											maxx = max(maxx, (a[i] & a[j] & a[k] & a[l] & a[m] & a[o] & a[p] & a[q] & a[r]));
										}
									}
								}	
							}	
						}	
					}
				}
			}
		}
	} else if (m == 10) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					for (int l = k + 1; l <= n; l++) {
						for (int m = l + 1; m <= n; m++) {
							for (int o = m + 1; o <= n; o++) {
								for (int p = o + 1; p <= n; p++) {
									for (int q = p + 1; q <= n; q++) {
										for (int r = q + 1; r <= n; r++) {
											for (int s = r + 1; s <= n; s++) {
												maxx = max(maxx, (a[i] & a[j] & a[k] & a[l] & a[m] & a[o] & a[p] & a[q] & a[r] & a[s]));
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
	cout << maxx;
	return 0;
}
