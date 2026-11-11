#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5;
ll n,m,a[N+10],ma=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll mi=1e17;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mi=min(mi,a[i]);
	}
	if(n>20){
		cout<<mi;
		return 0;
	}
	ll ma=-1;
	if(m==1){
		for(int i=1;i<=n;i++){
			ma=max(a[i],ma);
		}
	}
	else if(m==2){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				ll sum=a[i1]&a[i2];
				ma=max(sum,ma);
			}
		}
	}
	else if(m==3){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					ll sum=a[i1]&a[i2]&a[i3];
					ma=max(sum,ma);
				}
			}
		}
	}
	else if(m==3){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					ll sum=a[i1]&a[i2]&a[i3];
					ma=max(sum,ma);
				}
			}
		}
	}
	else if(m==4){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						ll sum=a[i1]&a[i2]&a[i3]&a[i4];
						ma=max(sum,ma);
					}
				}
			}
		}
	}
	else if(m==5){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							ll sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5];
							ma=max(sum,ma);
						}
					}
				}
			}
		}
	}
	else if(m==6){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								ll sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6];
								ma=max(sum,ma);
							}
						}
					}
				}
			}
		}
	}
	else if(m==7){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									ll sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7];
									ma=max(sum,ma);
								}
							}
						}
					}
				}
			}
		}
	}
	else if(m==8){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										ll sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8];
										ma=max(sum,ma);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if(m==9){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										for(int i9=i8+1;i9<=n;i9++){
											ll sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9];
											ma=max(sum,ma);
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
	else if(m==10){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										for(int i9=i8+1;i9<=n;i9++){
											for(int i10=i9+1;i10<=n;i10++){
												ll sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10];
												ma=max(sum,ma);
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
	else if(m==11){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										for(int i9=i8+1;i9<=n;i9++){
											for(int i10=i9+1;i10<=n;i10++){
												for(int i11=i10+1;i11<=n;i11++){
												ll sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11];
												ma=max(sum,ma);
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
	else if(m==12){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										for(int i9=i8+1;i9<=n;i9++){
											for(int i10=i9+1;i10<=n;i10++){
												for(int i11=i10+1;i11<=n;i11++){
													for(int i12=i11+1;i12<=n;i12++){
														ll sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12];
														ma=max(sum,ma);
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
	}

	else if(m==13){
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										for(int i9=i8+1;i9<=n;i9++){
											for(int i10=i9+1;i10<=n;i10++){
												for(int i11=i10+1;i11<=n;i11++){
													for(int i12=i11+1;i12<=n;i12++){
														ll sum=a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i3];
														ma=max(sum,ma);
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
	}
	cout<<ma;
	return 0;
}
