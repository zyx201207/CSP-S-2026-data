#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],ans=-1e9;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(m==2){
		for(int i1=1;i1<n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				int sum=a[i1]&a[i2];
				ans=max(ans,sum);
				//cout<<a[i1]<<" "<<a[i2]<<" "<<sum<<"\n";
			}
		}
	}else if(m==3){
		for(int i1=1;i1<n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					int sum=a[i1]&a[i2]&a[i3];
					ans=max(ans,sum);
				}
			}
		}
	}else if(m==4){
		for(int i1=1;i1<n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){	
						int sum=a[i1]&a[i2]&a[i3]&a[i4];
						ans=max(ans,sum);
					}
				}
			}
		}
	}else if(m==5){
		for(int i1=1;i1<n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){	
							int sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5];
							ans=max(ans,sum);
						}	
					}
				}
			}
		}
	}else if(m==6){
		for(int i1=1;i1<n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){	
								int sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6];
								ans=max(ans,sum);
							}	
						}	
					}
				}
			}
		}
	}else if(m==7){
		for(int i1=1;i1<n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){	
									int sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7];
									ans=max(ans,sum);
								}	
							}	
						}	
					}
				}
			}
		}
	}else if(m==8){
		for(int i1=1;i1<n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){	
										int sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8];
										ans=max(ans,sum);
									}		
								}	
							}	
						}	
					}
				}
			}
		}
	}else if(m==9){
		for(int i1=1;i1<n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										for(int i9=i8+1;i9<=n;i9++){	
											int sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9];
											ans=max(ans,sum);
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
	return 0;
}

