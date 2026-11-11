#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N];
bool f(bool x,bool y){
	return x > y;
}
int max_;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		sort(a+1,a+n+1,f);
		cout << a[1];
		return 0;
	}else if(m == n){
		int ans = a[1];
		for(int i= 2;i <= n;i++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int i2 = 1;i2 <= n;i2++){
				if(i == i2) continue;
				max_ = max(max_,a[i]&a[i2]);
			}
		}
	}else if(m == 3){
		for(int i = 1;i <= n;i++){
			for(int i2 = 1;i2 <= n;i2++){
				for(int i3 = 1;i3 <= n;i3++){
					if(i == i2 || i == i3) continue;
					max_ = max(max_,a[i]&a[i2]&a[i3]);
				}
				
			}
		}
	}else if(m == 4){
		for(int i = 1;i <= n;i++){
			for(int i2 = 1;i2 <= n;i2++){
				for(int i3 = 1;i3 <= n;i3++){
					for(int i4 = 1;i4 <= n;i4++){
						if(i == i2 || i == i3 || i == i4 || i3 == i4 || i2 == i3 || i2 == i4) continue;
						max_ = max(max_,a[i]&a[i2]&a[i3]&a[i4]);
					}
					
				}
				
			}
		}
	}else if(m == 5){
		for(int i = 1;i <= n;i++){
			for(int i2 = 1;i2 <= n;i2++){
				for(int i3 = 1;i3 <= n;i3++){
					for(int i4 = 1;i4 <= n;i4++){
						for(int i5 = 1;i5 <= n;i5++){
							if(i == i2 || i == i3 || i == i5 || i2 == i3 || i3 == i4 || i4 == i5 || i2 == i5 || i3 == i5 || i == i4) continue;
							max_ = max(max_,a[i]&a[i2]&a[i3]&a[i4]&a[i5]);
						}
					}
					
				}
				
			}
		}
	}else if(m == 6){
		for(int i = 1;i <= n;i++){
			for(int i2 = 1;i2 <= n;i2++){
				for(int i3 = 1;i3 <= n;i3++){
					for(int i4 = 1;i4 <= n;i4++){
						for(int i5 = 1;i5 <= n;i5++){
							for(int i6 = 1;i6 <= n;i6++){
								if(i == i2 || i == i3 || i == i5 || i2 == i3 || i3 == i4 || i4 == i5 || i2 == i5 || i3 == i5 || i == i4 || i == i6 || i2 == i6 || i3 == i6 || i4 ==i6 || i5 == i6) continue;
								max_ = max(max_,a[i]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]);
							}
						}
					}
					
				}
				
			}
		}
	}else if(m == 7){
		for(int i = 1;i <= n;i++){
			for(int i2 = 1;i2 <= n;i2++){
				for(int i3 = 1;i3 <= n;i3++){
					for(int i4 = 1;i4 <= n;i4++){
						for(int i5 = 1;i5 <= n;i5++){
							for(int i6 = 1;i6 <= n;i6++){
								for(int i7 = 1;i7 <= n;i7++){
									if(i == i7 || i2 == i7||i3==i7||i4==i7||i5==i7||i6==i7||i == i2 || i == i3 || i == i5 || i2 == i3 || i3 == i4 || i4 == i5 || i2 == i5 || i3 == i5 || i == i4 || i == i6 || i2 == i6 || i3 == i6 || i4 ==i6 || i5 == i6) continue;
									max_ = max(max_,a[i]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]);
								}
								
							}
						}
					}
					
				}
				
			}
		}
	}else if(m == 8){
		for(int i = 1;i <= n;i++){
			for(int i2 = 1;i2 <= n;i2++){
				for(int i3 = 1;i3 <= n;i3++){
					for(int i4 = 1;i4 <= n;i4++){
						for(int i5 = 1;i5 <= n;i5++){
							for(int i6 = 1;i6 <= n;i6++){
								for(int i7 = 1;i7 <= n;i7++){
									for(int i8 = 1;i8 <= n;i8++){
										if(i==i8||i2 == i8||i3==i8||i4==i8||i5==i8||i6==i8||i7==i8||i == i7 || i2 == i7||i3==i7||i4==i7||i5==i7||i6==i7||i == i2 || i == i3 || i == i5 || i2 == i3 || i3 == i4 || i4 == i5 || i2 == i5 || i3 == i5 || i == i4 || i == i6 || i2 == i6 || i3 == i6 || i4 ==i6 || i5 == i6) continue;
										max_ = max(max_,a[i]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]);
									}
								}
								
							}
						}
					}
					
				}
				
			}
		}
	}else if(m == 9){
		for(int i = 1;i <= n;i++){
			for(int i2 = 1;i2 <= n;i2++){
				for(int i3 = 1;i3 <= n;i3++){
					for(int i4 = 1;i4 <= n;i4++){
						for(int i5 = 1;i5 <= n;i5++){
							for(int i6 = 1;i6 <= n;i6++){
								for(int i7 = 1;i7 <= n;i7++){
									for(int i8 = 1;i8 <= n;i8++){
										for(int i9 = 1;i9 <= n;i9++){
											if(i==i9||i2 == i9||i3==i9||i4==i9||i5==i9||i6==i9||i7==i9||i8==i9||i==i8||i2 == i8||i3==i8||i4==i8||i5==i8||i6==i8||i7==i8||i == i7 || i2 == i7||i3==i7||i4==i7||i5==i7||i6==i7||i == i2 || i == i3 || i == i5 || i2 == i3 || i3 == i4 || i4 == i5 || i2 == i5 || i3 == i5 || i == i4 || i == i6 || i2 == i6 || i3 == i6 || i4 ==i6 || i5 == i6) continue;
											max_ = max(max_,a[i]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]);
										}
										
									}
								}
								
							}
						}
					}
					
				}
				
			}
		}
	}else{
		for(int i = 1;i <= n;i++){
			for(int i2 = 1;i2 <= n;i2++){
				for(int i3 = 1;i3 <= n;i3++){
					for(int i4 = 1;i4 <= n;i4++){
						for(int i5 = 1;i5 <= n;i5++){
							for(int i6 = 1;i6 <= n;i6++){
								for(int i7 = 1;i7 <= n;i7++){
									for(int i8 = 1;i8 <= n;i8++){
										for(int i9 = 1;i9 <= n;i9++){
											for(int i10 = 1;i10 <= n;i10++){
												if(i==i10||i2 == i10||i3==i10||i4==i10||i5==i10||i6==i10||i7==i10||i8==i10||i9==i10||i==i9||i2 == i9||i3==i9||i4==i9||i5==i9||i6==i9||i7==i9||i8==i9||i==i8||i2 == i8||i3==i8||i4==i8||i5==i8||i6==i8||i7==i8||i == i7 || i2 == i7||i3==i7||i4==i7||i5==i7||i6==i7||i == i2 || i == i3 || i == i5 || i2 == i3 || i3 == i4 || i4 == i5 || i2 == i5 || i3 == i5 || i == i4 || i == i6 || i2 == i6 || i3 == i6 || i4 ==i6 || i5 == i6) continue;
												max_ = max(max_,a[i]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]);
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
	cout << max_;
	return 0;
}
