#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans1,cnt,cnt1,cnt2,b[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a[1];
	ans1=a[1];
	if(a[1]<4) {
		b[a[1]]++;
		cnt2++;
	}
	for(int i=2; i<=n; i++) {
		cin>>a[i];
		ans1=ans1&a[i];
		if(a[i]==i-1) {
			cnt++;
		}
		if(log2(a[i]+1)==int(log2(a[i]+1))) {
			cnt1++;
		}
		if(a[i]<4) {
			b[a[i]]++;
			cnt2++;
		}
	}
	sort(a+1,a+1+n);
	if(n==m) {
		cout<<ans1;
		return 0;
	}
	if(cnt==n-1  && a[1]==0) {
		cout<<0;
		return 0;
	}
	if(cnt1==n-1 && log2(a[1]+1)==int(log2(a[1]+1))) {
		ans1=a[n];
		for(int i=n-1; i>=n-m+1; i--) {
			ans1=ans1&a[i];
		}
		cout<<ans1;
		return 0;
	}
	if(m==1) {
		cout<<a[n];
		return 0;
	}
	if(m==2) {
		ans1=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				ans1=max(ans1,a[i]&a[j]);
			}
		}
		cout<<ans1;
		return 0;
	}
	if(cnt2==n) {
		if(b[4]>=m) {
			cout<<4;
		} else if(b[2]+b[3]>=m) {
			cout<<2;
		} else if(b[1]+b[3]>=m) {
			cout<<1;
		} else {
			cout<<0;
		}
		return 0;
	}
	if(m==n-1) {
		ans1=a[n];
		for(int i=n-1; i>1; i--) {
			ans1=ans1&a[i];
		}
		cout<<ans1;
		return 0;
	}
	int answer=0;
	if(m==3) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				for(int k=j+1; k<=n; k++) {
					answer=max(answer,a[i]&a[j]&a[k]);
				}
			}
		}
	}
	if(m==4) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				for(int k=j+1; k<=n; k++) {
					for(int l=k+1; l<=n; l++) {
						answer=max(answer,a[i]&a[j]&a[k]&a[l]);
					}
				}
			}
		}
	}
	if(m==5) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				for(int k=j+1; k<=n; k++) {
					for(int l=k+1; l<=n; l++) {
						for(int o=l+1; o<=n; o++) {
							answer=max(answer,a[i]&a[j]&a[k]&a[l]&a[o]);
						}
					}
				}
			}
		}
	}
	if(m==6) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				for(int k=j+1; k<=n; k++) {
					for(int l=k+1; l<=n; l++) {
						for(int o=l+1; o<=n; o++) {
							for(int p=o+1; p<=n; p++) {
								answer=max(answer,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]);
							}
						}
					}
				}
			}
		}
	}
	if(m==7) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				for(int k=j+1; k<=n; k++) {
					for(int l=k+1; l<=n; l++) {
						for(int o=l+1; o<=n; o++) {
							for(int p=o+1; p<=n; p++) {
								for(int q=p+1; q<=n; q++) {
									answer=max(answer,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]);
								}
							}
						}
					}
				}
			}
		}
	}
	if(m==8) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				for(int k=j+1; k<=n; k++) {
					for(int l=k+1; l<=n; l++) {
						for(int o=l+1; o<=n; o++) {
							for(int p=o+1; p<=n; p++) {
								for(int q=p+1; q<=n; q++) {
									for(int r=q+1; r<=n; r++) {
										answer=max(answer,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(m==8) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				for(int k=j+1; k<=n; k++) {
					for(int l=k+1; l<=n; l++) {
						for(int o=l+1; o<=n; o++) {
							for(int p=o+1; p<=n; p++) {
								for(int q=p+1; q<=n; q++) {
									for(int r=q+1; r<=n; r++) {
										for(int s=r+1; s<=n; s++) {
											answer=max(answer,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]);
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
	if(m==9) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				for(int k=j+1; k<=n; k++) {
					for(int l=k+1; l<=n; l++) {
						for(int o=l+1; o<=n; o++) {
							for(int p=o+1; p<=n; p++) {
								for(int q=p+1; q<=n; q++) {
									for(int r=q+1; r<=n; r++) {
										for(int s=r+1; s<=n; s++) {
											for(int t=s+1; t<=n; t++) {
												answer=max(answer,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]);
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
	if(m==10) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				for(int k=j+1; k<=n; k++) {
					for(int l=k+1; l<=n; l++) {
						for(int o=l+1; o<=n; o++) {
							for(int p=o+1; p<=n; p++) {
								for(int q=p+1; q<=n; q++) {
									for(int r=q+1; r<=n; r++) {
										for(int s=r+1; s<=n; s++) {
											for(int t=s+1; t<=n; t++) {
												for(int u=t+1; u<=n; u++) {
													answer=max(answer,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]);
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
	cout<<answer;
	return 0;
}
