#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m;
int a[N];
int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	if(m == 2) {
		int mx = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(j == i) continue;
				int x = a[i] & a[j];
				mx = max(mx, x); 
			}
		}
		cout << mx;
	}
	if(m == n) {
		int mx;
		for(int i = 1; i <= n; i++) {
			mx = a[i] & a[i - 1];
		}
		cout << mx;
	}
	if(m == 1) {
		sort(a + 1, a + 1 + n); 
		 cout << a[1];
	} 
	if(m == 3) {
		int mx = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				for(int k = 1; k <= n; k++) {
					if(i == j || i == k || j == k) continue;
					int x = a[i] & a[j] & a[k];
					mx = max(mx, x);
				}
			}
		}
		cout << mx;
	}
	if(m == 4) {
		int mx = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; i++) {
				for(int k = 1; k <= n; k++) {
					for(int q = 1; q <= n; q++) {
						if(i == j || i == k ||i == q || j == k ||j == q || k == q) continue;
						int x = a[i] & a[j] & a[k] & a[q];
						mx = max(mx, x);
					}
				}
			}
		}
		cout << mx;
	}
	if(m == 5) {
		int mx = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; i++) {
				for(int k = 1; k <= n; k++) {
					for(int q = 1; q <= n; q++) {
						for(int w = 1; w <= n; w++) {
							if(i == j || i == k ||i == q || i == w || j == k ||j == q || j == w || k == q || k == w || q == w) continue;
							int x = a[i] & a[j] & a[k] & a[q] & a[w];
							mx = max(mx, x);
						}
					
					}
				}
			}
		}
		cout << mx;
	}
	if(m == 6) {
		int mx = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; i++) {
				for(int k = 1; k <= n; k++) {
					for(int q = 1; q <= n; q++) {
						for(int w = 1; w <= n; w++) {
							for(int rp = 1; rp <= n; rp++) {
								if(i == j || i == k || i == q || i == w || i == rp || j == k || j == q ||j == w ||j == rp ||k == q|| k == w || k == rp ||q == w || q == rp || w == rp) continue;
								int x = a[i] & a[j] & a[k] & a[q] & a[w] & a[rp];
								mx = max(mx, x);
							}
						}
					
					}
				}
			}
		}
		cout << mx;		
	}	
	if(m == 7) {
		int mx = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; i++) {
				for(int k = 1; k <= n; k++) {
					for(int q = 1; q <= n; q++) {
						for(int w = 1; w <= n; w++) {
							for(int rp = 1; rp <= n; rp++) {
								for(int p = 1; p <= n; p++) {
									if(i == j || i == k || i == q || i == w || i == rp || i == p || j == k || j == q ||j == w ||j == rp  || j == p ||k == q|| k == w || k == rp || k == p ||q == w || q == rp || q == p || w == rp || w == p || rp == p) continue;
									int x = a[i] & a[j] & a[k] & a[q] & a[w] & a[rp] & a [p];
									mx = max(mx, x);
								}
							}
						}
					
					}
				}
			}
		}
		cout << mx;
	}
	if(m == 8) {
		int mx = 0;
		for(int a1 = 1; a1 <= n; a1++) {
			for(int a2 = 1; a2 <= n; a2++) {
				for(int a3 = 1; a3 <= n; a3++) {
					for(int a4 = 1; a4 <= n; a4++) {
						for(int a5 = 1; a5 <= n; a5++) {
							for(int a6 = 1; a6 <= n; a6++) {
								for(int a7 = 1; a7 <= n; a7++) {
									for(int a8 = 1; a8 <= n; a8++) {
										if(a1 == a2 || a1 == a3 || a1 == a4 || a1 == a5 || a1 == a6 || a1 == a7 || a1 == a8 ||
										   a2 == a3 || a2 == a4 || a2 == a5 || a2 == a6 || a2 == a7 || a2 == a8 ||
										   a3 == a4 || a3 == a5 || a3 == a6 || a3 == a7 || a3 == a8 ||
										   a4 == a5 || a4 == a6 || a4 == a7 || a4 == a8 || 
										   a5 == a6 || a5 == a7 || a5 == a8 || 
										   a6 == a7 || a6 == a8 ||
										   a7 == a8
										) continue;
										int x = a[a1] & a[a2] & a[a3] & a[a4] & a[a5] & a[a6] & a[a7] & a[a8];
										mx = max(mx, x);
									}
								}
							}
						}
					}
				}
			}
		}
		cout << mx;
	} 
	if(m == 9) {
		int mx = 0;
		for(int a1 = 1; a1 <= n; a1++) {
			for(int a2 = 1; a2 <= n; a2++) {
				for(int a3 = 1; a3 <= n; a3++) {
					for(int a4 = 1; a4 <= n; a4++) {
						for(int a5 = 1; a5 <= n; a5++) {
							for(int a6 = 1; a6 <= n; a6++) {
								for(int a7 = 1; a7 <= n; a7++) {
									for(int a8 = 1; a8 <= n; a8++) {
										for(int a9 = 1; a9 <= n; a9++) {
											if(a1 == a2 || a1 == a3 || a1 == a4 || a1 == a5 || a1 == a6 || a1 == a7 || a1 == a8 || a1 == a9 ||
											   a2 == a3 || a2 == a4 || a2 == a5 || a2 == a6 || a2 == a7 || a2 == a8 || a2 == a9 ||
											   a3 == a4 || a3 == a5 || a3 == a6 || a3 == a7 || a3 == a8 || a3 == a9 ||
											   a4 == a5 || a4 == a6 || a4 == a7 || a4 == a8 || a4 == a9 ||
											   a5 == a6 || a5 == a7 || a5 == a8 || a5 == a9 ||
											   a6 == a7 || a6 == a8 || a6 == a9 ||
											   a7 == a8 || a7 == a9 ||
											   a8 == a9
											) continue;
											int x = a[a1] & a[a2] & a[a3] & a[a4] & a[a5] & a[a6] & a[a7] & a[a8] & a[a9];
											mx = max(mx, x);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << mx;
	}
	if(m == 10) {
		int mx = 0;
		for(int a1 = 1; a1 <= n; a1++) {
			for(int a2 = 1; a2 <= n; a2++) {
				for(int a3 = 1; a3 <= n; a3++) {
					for(int a4 = 1; a4 <= n; a4++) {
						for(int a5 = 1; a5 <= n; a5++) {
							for(int a6 = 1; a6 <= n; a6++) {
								for(int a7 = 1; a7 <= n; a7++) {
									for(int a8 = 1; a8 <= n; a8++) {
										for(int a9 = 1; a9 <= n; a9++) {
											for(int a10 = 1; a10 <= n; a10++) {
												if(a1 == a2 || a1 == a3 || a1 == a4 || a1 == a5 || a1 == a6 || a1 == a7 || a1 == a8 || a1 == a9 || a1 == a10 ||
												   a2 == a3 || a2 == a4 || a2 == a5 || a2 == a6 || a2 == a7 || a2 == a8 || a2 == a9 || a2 == a10 ||
												   a3 == a4 || a3 == a5 || a3 == a6 || a3 == a7 || a3 == a8 || a3 == a9 || a3 == a10 ||
												   a4 == a5 || a4 == a6 || a4 == a7 || a4 == a8 || a4 == a9 || a4 == a10 ||
												   a5 == a6 || a5 == a7 || a5 == a8 || a5 == a9 || a5 == a10 ||
												   a6 == a7 || a6 == a8 || a6 == a9 || a6 == a10 ||
												   a7 == a8 || a7 == a9 || a7 == a10 ||
												   a8 == a9 || a8 == a10 ||
												   a9 == a10
												) continue;
												int x = a[a1] & a[a2] & a[a3] & a[a4] & a[a5] & a[a6] & a[a7] & a[a8] & a[a9] & a[a10];
												mx = max(mx, x);
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
		cout << mx;
	}
	if(m == 11) {
		int mx = 0;
		for(int a1 = 1; a1 <= n; a1++) {
			for(int a2 = 1; a2 <= n; a2++) {
				for(int a3 = 1; a3 <= n; a3++) {
					for(int a4 = 1; a4 <= n; a4++) {
						for(int a5 = 1; a5 <= n; a5++) {
							for(int a6 = 1; a6 <= n; a6++) {
								for(int a7 = 1; a7 <= n; a7++) {
									for(int a8 = 1; a8 <= n; a8++) {
										for(int a9 = 1; a9 <= n; a9++) {
											for(int a10 = 1; a10 <= n; a10++) {
												for(int a11 = 1; a11 <= n; a11++) {
													if(a1 == a2 || a1 == a3 || a1 == a4 || a1 == a5 || a1 == a6 || a1 == a7 || a1 == a8 || a1 == a9 || a1 == a10 || a1 == a11 ||
												   	   a2 == a3 || a2 == a4 || a2 == a5 || a2 == a6 || a2 == a7 || a2 == a8 || a2 == a9 || a2 == a10 || a2 == a11 ||
												   	   a3 == a4 || a3 == a5 || a3 == a6 || a3 == a7 || a3 == a8 || a3 == a9 || a3 == a10 || a3 == a11 ||
												   	   a4 == a5 || a4 == a6 || a4 == a7 || a4 == a8 || a4 == a9 || a4 == a10 || a4 == a11 ||
												       a5 == a6 || a5 == a7 || a5 == a8 || a5 == a9 || a5 == a10 || a5 == a11 ||
												       a6 == a7 || a6 == a8 || a6 == a9 || a6 == a10 || a6 == a11 ||
												       a7 == a8 || a7 == a9 || a7 == a10 || a7 == a11 ||
												       a8 == a9 || a8 == a10 || a8 == a11 ||
												       a9 == a10 || a9 == a11 ||
												       a10 == a11
												    ) continue;
													int x = a[a1] & a[a2] & a[a3] & a[a4] & a[a5] & a[a6] & a[a7] & a[a8] & a[a9] & a[a10] & a[a11];
													mx = max(mx, x);
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
		cout << mx;
	}
	if(m == 12) {
		int mx = 0;
		for(int a1 = 1; a1 <= n; a1++) {
			for(int a2 = 1; a2 <= n; a2++) {
				for(int a3 = 1; a3 <= n; a3++) {
					for(int a4 = 1; a4 <= n; a4++) {
						for(int a5 = 1; a5 <= n; a5++) {
							for(int a6 = 1; a6 <= n; a6++) {
								for(int a7 = 1; a7 <= n; a7++) {
									for(int a8 = 1; a8 <= n; a8++) {
										for(int a9 = 1; a9 <= n; a9++) {
											for(int a10 = 1; a10 <= n; a10++) {
												for(int a11 = 1; a11 <= n; a11++) {
													for(int a12 = 1; a12 <= n; a12++) {
														if(a1 == a2 || a1 == a3 || a1 == a4 || a1 == a5 || a1 == a6 || a1 == a7 || a1 == a8 || a1 == a9 || a1 == a10 || a1 == a11 || a1 == a12 ||
												   	   a2 == a3 || a2 == a4 || a2 == a5 || a2 == a6 || a2 == a7 || a2 == a8 || a2 == a9 || a2 == a10 || a2 == a11 || a2 == a12 ||
												   	   a3 == a4 || a3 == a5 || a3 == a6 || a3 == a7 || a3 == a8 || a3 == a9 || a3 == a10 || a3 == a11 || a3 == a12 ||
												   	   a4 == a5 || a4 == a6 || a4 == a7 || a4 == a8 || a4 == a9 || a4 == a10 || a4 == a11 || a4 == a12 ||
												       a5 == a6 || a5 == a7 || a5 == a8 || a5 == a9 || a5 == a10 || a5 == a11 || a5 == a12 ||
												       a6 == a7 || a6 == a8 || a6 == a9 || a6 == a10 || a6 == a11 || a6 == a12 ||
												       a7 == a8 || a7 == a9 || a7 == a10 || a7 == a11 || a7 == a12 ||
												       a8 == a9 || a8 == a10 || a8 == a11 || a8 == a12 ||
												       a9 == a10 || a9 == a11 || a9 == a12 ||
												       a10 == a11 || a10 == a12 ||
												       a11 == a12 ||
												    ) continue;
													int x = a[a1] & a[a2] & a[a3] & a[a4] & a[a5] & a[a6] & a[a7] & a[a8] & a[a9] & a[a10] & a[a11] & a[a12];
													mx = max(mx, x);
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
		}
		cout << mx;
	}
	return 0;
}

