#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10000],k,mxxx=-111,mxx=-111,s,r,rp,mx=-111,www=-111;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxxx=max(mxxx,a[i]);
	}
	if(m==1){
		cout<<mxxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mxx=max(mxx,i&j);
			}
		}
		cout<<mxx;
		return 0;
	}
	if(m==n){
		s=a[1];
		for(int i=2;i<=n;i++){
			s=s&a[i];
		}
		cout<<s;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			if(i==1){
				r=a[2];
				rp=2;
			}
			else{
				r=a[1];
				rp=1;
			}
			for(int j=1;j<=n;j++){
				if(j!=i&&j!=rp){
					r=r&a[j];
				}
			}
			mx=max(mx,r);
		}
		cout<<mx;
		return 0;
	}
	if(n<=20){
		if(m==3){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int j1=j+1;j1<=n;j1++){
						www=max(www,i&j&j1);
					}
				}
			}	
		}
		if(m==4){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int j1=j+1;j1<=n;j1++){
						for(int j2=j1+1;j2<=n;j2++){
							www=max(www,i&j&j1&j2);
						}
					}
				}
			}	
		}
		if(m==5){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int j1=j+1;j1<=n;j1++){
						for(int j2=j1+1;j2<=n;j2++){
							for(int j3=j2+1;j3<=n;j3++){
								www=max(www,i&j&j1&j2&j3);
							}
						}
					}
				}
			}	
		}
		if(m==6){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int j1=j+1;j1<=n;j1++){
						for(int j2=j1+1;j2<=n;j2++){
							for(int j3=j2+1;j3<=n;j3++){
								for(int j4=j3+1;j4<=n;j4++){
									www=max(www,i&j&j1&j2&j3&j4);
								}
							}
						}
					}
				}
			}	
		}
		if(m==7){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int j1=j+1;j1<=n;j1++){
						for(int j2=j1+1;j2<=n;j2++){
							for(int j3=j2+1;j3<=n;j3++){
								for(int j4=j3+1;j4<=n;j4++){
									for(int j5=j4+1;j5<=n;j5++){
										www=max(www,i&j&j1&j2&j3&j4&j5);
									}
								}
							}
						}
					}
				}
			}	
		}
		if(m==8){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int j1=j+1;j1<=n;j1++){
						for(int j2=j1+1;j2<=n;j2++){
							for(int j3=j2+1;j3<=n;j3++){
								for(int j4=j3+1;j4<=n;j4++){
									for(int j5=j4+1;j5<=n;j5++){
										for(int j6=j5+1;j6<=n;j6++){
											www=max(www,i&j&j1&j2&j3&j4&j5&j6);
										}
									}
								}
							}
						}
					}
				}
			}	
		}
		if(m==9){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int j1=j+1;j1<=n;j1++){
						for(int j2=j1+1;j2<=n;j2++){
							for(int j3=j2+1;j3<=n;j3++){
								for(int j4=j3+1;j4<=n;j4++){
									for(int j5=j4+1;j5<=n;j5++){
										for(int j6=j5+1;j6<=n;j6++){
											for(int j7=j6+1;j7<=n;j7++){
												www=max(www,i&j&j1&j2&j3&j4&j5&j6&j7);
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
		if(m==10){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int j1=j+1;j1<=n;j1++){
						for(int j2=j1+1;j2<=n;j2++){
							for(int j3=j2+1;j3<=n;j3++){
								for(int j4=j3+1;j4<=n;j4++){
									for(int j5=j4+1;j5<=n;j5++){
										for(int j6=j5+1;j6<=n;j6++){
											for(int j7=j6+1;j7<=n;j7++){
												for(int j8=j7+1;j8<=n;j8++){
													www=max(www,i&j&j1&j2&j3&j4&j5&j6&j7&j8);
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
		if(m==11){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int j1=j+1;j1<=n;j1++){
						for(int j2=j1+1;j2<=n;j2++){
							for(int j3=j2+1;j3<=n;j3++){
								for(int j4=j3+1;j4<=n;j4++){
									for(int j5=j4+1;j5<=n;j5++){
										for(int j6=j5+1;j6<=n;j6++){
											for(int j7=j6+1;j7<=n;j7++){
												for(int j8=j7+1;j8<=n;j8++){
													for(int j9=j8+1;j9<=n;j9++){
														www=max(www,i&j&j1&j2&j3&j4&j5&j6&j7&j8&j9);
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
		if(m==12){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int j1=j+1;j1<=n;j1++){
						for(int j2=j1+1;j2<=n;j2++){
							for(int j3=j2+1;j3<=n;j3++){
								for(int j4=j3+1;j4<=n;j4++){
									for(int j5=j4+1;j5<=n;j5++){
										for(int j6=j5+1;j6<=n;j6++){
											for(int j7=j6+1;j7<=n;j7++){
												for(int j8=j7+1;j8<=n;j8++){
													for(int j9=j8+1;j9<=n;j9++){
														for(int j10=j9+1;j10<=n;j10++){
															www=max(www,i&j&j1&j2&j3&j4&j5&j6&j7&j8&j9&j10);
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
 	if(m==13){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int j1=j+1;j1<=n;j1++){
						for(int j2=j1+1;j2<=n;j2++){
							for(int j3=j2+1;j3<=n;j3++){
								for(int j4=j3+1;j4<=n;j4++){
									for(int j5=j4+1;j5<=n;j5++){
										for(int j6=j5+1;j6<=n;j6++){
											for(int j7=j6+1;j7<=n;j7++){
												for(int j8=j7+1;j8<=n;j8++){
													for(int j9=j8+1;j9<=n;j9++){
														for(int j10=j9+1;j10<=n;j10++){
															for(int j11=j10+1;j11<=n;j11++){
																www=max(www,i&j&j1&j2&j3&j4&j5&j6&j7&j8&j9&j10&j11);
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
		}
	}
	return 0;
}
