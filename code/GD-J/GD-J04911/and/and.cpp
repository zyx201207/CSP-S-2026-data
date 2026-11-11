#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxv=0,ans=0,q=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxv=max(a[i],maxv);
	}
	if(m==1){
		cout<<maxv;
		return 0;
	} 
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		ans=a[2];
		for(int j=3;j<=n;j++){
			ans=ans&a[j];
		}
		q=ans;
		for(int i=2;i<=n;i++){
			ans=a[1];
			for(int j=2;j<=n;j++){
				if(j==i){
					continue;
				}
				ans=ans&a[j];
			}
			q=max(q,ans);
		}
		cout<<q;
	}
	
	if(m>30){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int i2=1;i2<i;i2++){
				for(int i3=1;i3<i2;i3++){
					ans=max(ans,a[i]&a[i3]&a[i2]);
				}
			}	
		}
		cout<<ans;
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int i2=1;i2<i;i2++){
				for(int i3=1;i3<i2;i3++){
					for(int i4=1;i4<i3;i4++){
						ans=max(ans,a[i]&a[i2]&a[i3]&a[i4]);
					}
				}
			}	
		}
		cout<<ans;
	}
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int i2=1;i2<i;i2++){
				for(int i3=1;i3<i2;i3++){
					for(int i4=1;i4<i3;i4++){
						for(int i5=1;i5<i4;i5++){
							ans=max(ans,a[i]&a[i2]&a[i3]&a[i4]&a[i5]);
						}
					}
				}
			}	
		}
		cout<<ans;
	}
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int i2=1;i2<i;i2++){
				for(int i3=1;i3<i2;i3++){
					for(int i4=1;i4<i3;i4++){
						for(int i5=1;i5<i4;i5++){
							for(int i6=1;i6<i5;i6++){
								ans=max(ans,a[i]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]);
							}
						}
					}
				}
			}	
		}
		cout<<ans;
	}
	if(m==7){
		for(int i=1;i<=n;i++){
			for(int i2=1;i2<i;i2++){
				for(int i3=1;i3<i2;i3++){
					for(int i4=1;i4<i3;i4++){
						for(int i5=1;i5<i4;i5++){
							for(int i6=1;i6<i5;i6++){
								for(int i7=1;i7<i6;i7++){
									ans=max(ans,a[i]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]);
								}
							}
						}
					}
				}
			}	
		}
		cout<<ans;
	}
	if(m==8){
		for(int i=1;i<=n;i++){
			for(int i2=1;i2<i;i2++){
				for(int i3=1;i3<i2;i3++){
					for(int i4=1;i4<i3;i4++){
						for(int i5=1;i5<i4;i5++){
							for(int i6=1;i6<i5;i6++){
								for(int i7=1;i7<i6;i7++){
									for(int i8=1;i8<i7;i8++){
										ans=max(ans,a[i]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]);
									}
								}
							}
						}
					}
				}
			}	
		}
		cout<<ans;
	}
	if(m==9){
		for(int i=1;i<=n;i++){
			for(int i2=1;i2<i;i2++){
				for(int i3=1;i3<i2;i3++){
					for(int i4=1;i4<i3;i4++){
						for(int i5=1;i5<i4;i5++){
							for(int i6=1;i6<i5;i6++){
								for(int i7=1;i7<i6;i7++){
									for(int i8=1;i8<i7;i8++){
										for(int i9=1;i9<i8;i9++){
											ans=max(ans,a[i]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]);
										}
									}
								}
							}
						}
					}
				}
			}	
		}
		cout<<ans;
	}
	if(m==10){
		for(int i=1;i<=n;i++){
			for(int i2=1;i2<i;i2++){
				for(int i3=1;i3<i2;i3++){
					for(int i4=1;i4<i3;i4++){
						for(int i5=1;i5<i4;i5++){
							for(int i6=1;i6<i5;i6++){
								for(int i7=1;i7<i6;i7++){
									for(int i8=1;i8<i7;i8++){
										for(int i9=1;i9<i8;i9++){
											for(int i10=1;i10<i9;i10++){
												ans=max(ans,a[i]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]);
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
		cout<<ans;
	}
	return 0;
}

