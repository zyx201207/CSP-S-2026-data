#include<bits/stdc++.h>
using namespace std;
long long a1[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a1[i];
	}
	long long x=0,mx=-1e9;
	if(m==1){
		for(long long a=1;a<=n;a++){
			mx=(a1[a],mx);
		}
	}
	else if(m==2){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				x=a1[a]&a1[b];
				mx=max(mx,x);
			}
		}
	}
	else if(m==3){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
				x=a1[a]&a1[b]&a1[c];
				mx=max(mx,x);					
				}
			}
		}
	}
	else if(m==3){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						x=a1[a]&a1[b]&a1[c]&a1[d];
						mx=max(mx,x);
					}
				}
			}
		}
	}
	else if(m==4){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e];
							mx=max(mx,x);
						}
					}
				}
			}
		}
	}
	else if(m==5){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f];
								mx=max(mx,x);
							}
						}
					}
				}
			}
		}
	}	
	else if(m==6){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g];
									mx=max(mx,x);
								}
							}
						}
					}
				}
			}
		}
	}
	else if(m==7){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h];
										mx=max(mx,x);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if(m==8){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i];
											mx=max(mx,x);
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
	else if(m==9){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(int j=i+1;j<=n;j++){
											x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j];
											mx=max(mx,x);
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
	else if(m==10){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(long long j=i+1;j<=n;j++){
												for(long long k=j+1;k<=n;k++){
													x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k];
													mx=max(mx,x);
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
	else if(m==11){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(long long j=i+1;j<=n;j++){
												for(long long k=j+1;k<=n;k++){
													for(long long l=k+1;l<=n;l++){
														x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k];
														mx=max(mx,x);
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
	else if(m==12){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(long long j=i+1;j<=n;j++){
												for(long long k=j+1;k<=n;k++){
													for(long long l=k+1;l<=n;l++){
														for(long long o=l+1;o<=n;o++){
															x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k]&a1[o];
															mx=max(mx,x);
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
	else if(m==13){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(long long j=i+1;j<=n;j++){
												for(long long k=j+1;k<=n;k++){
													for(long long l=k+1;l<=n;l++){
														for(long long o=l+1;o<=n;o++){
															for(long long p=o+1;p<=n;p++){
																x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k]&a1[o]&a1[p];
																mx=max(mx,x);
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
	else if(m==14){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(long long j=i+1;j<=n;j++){
												for(long long k=j+1;k<=n;k++){
													for(long long l=k+1;l<=n;l++){
														for(long long o=l+1;o<=n;o++){
															for(long long p=o+1;p<=n;p++){
																for(long long q=p+1;q<=n;q++){
																	x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k]&a1[o]&a1[p]&a1[q];
																	mx=max(mx,x);
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
	}	
	else if(m==15){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(long long j=i+1;j<=n;j++){
												for(long long k=j+1;k<=n;k++){
													for(long long l=k+1;l<=n;l++){
														for(long long o=l+1;o<=n;o++){
															for(long long p=o+1;p<=n;p++){
																for(long long q=p+1;q<=n;q++){
																	for(long long r=q+1;r<=n;r++){
																		x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k]&a1[o]&a1[p]&a1[q]&a1[r];
																		mx=max(mx,x);
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
		}
	}
	else if(m==16){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(long long j=i+1;j<=n;j++){
												for(long long k=j+1;k<=n;k++){
													for(long long l=k+1;l<=n;l++){
														for(long long o=l+1;o<=n;o++){
															for(long long p=o+1;p<=n;p++){
																for(long long q=p+1;q<=n;q++){
																	for(long long r=q+1;r<=n;r++){
																		for(long long s=r+1;s<=n;s++){
																			x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k]&a1[o]&a1[p]&a1[q]&a1[r]&a1[s];
																			mx=max(mx,x);
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
			}
		}
	}
	else if(m==17){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(long long j=i+1;j<=n;j++){
												for(long long k=j+1;k<=n;k++){
													for(long long l=k+1;l<=n;l++){
														for(long long o=l+1;o<=n;o++){
															for(long long p=o+1;p<=n;p++){
																for(long long q=p+1;q<=n;q++){
																	for(long long r=q+1;r<=n;r++){
																		for(long long s=r+1;s<=n;s++){
																			for(long long t=s+1;t<=n;t++){
																				x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k]&a1[o]&a1[p]&a1[q]&a1[r]&a1[s]&a1[t];
																				mx=max(mx,x);
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
				}
			}
		}
	}
	else if(m==18){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(long long j=i+1;j<=n;j++){
												for(long long k=j+1;k<=n;k++){
													for(long long l=k+1;l<=n;l++){
														for(long long o=l+1;o<=n;o++){
															for(long long p=o+1;p<=n;p++){
																for(long long q=p+1;q<=n;q++){
																	for(long long r=q+1;r<=n;r++){
																		for(long long s=r+1;s<=n;s++){
																			for(long long t=s+1;t<=n;t++){
																				for(long long u=t+1;t<=n;t++){
																					x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k]&a1[o]&a1[p]&a1[q]&a1[r]&a1[s]&a1[t]&a1[u];
																					mx=max(mx,x);
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
					}
				}
			}
		}
	}
	else if(m==19){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(long long j=i+1;j<=n;j++){
												for(long long k=j+1;k<=n;k++){
													for(long long l=k+1;l<=n;l++){
														for(long long o=l+1;o<=n;o++){
															for(long long p=o+1;p<=n;p++){
																for(long long q=p+1;q<=n;q++){
																	for(long long r=q+1;r<=n;r++){
																		for(long long s=r+1;s<=n;s++){
																			for(long long t=s+1;t<=n;t++){
																				for(long long u=t+1;t<=n;t++){
																					for(long long v=u+1;v<=n;v++){
																						x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k]&a1[o]&a1[p]&a1[q]&a1[r]&a1[s]&a1[t]&a1[u]&a1[v];
																						mx=max(mx,x);
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
						}
					}
				}
			}
		}
	}
	else if(m==20){
		for(long long a=1;a<=n;a++){
			for(long long b=a+1;b<=n;b++){
				for(long long c=b+1;c<=n;c++){
					for(long long d=c+1;d<=n;d++){
						for(long long e=d+1;e<=n;e++){
							for(long long f=e+1;f<=n;f++){
								for(long long g=f+1;g<=n;g++){
									for(long long h=g+1;h<=n;h++){
										for(long long i=h+1;i<=n;i++){
											for(long long j=i+1;j<=n;j++){
												for(long long k=j+1;k<=n;k++){
													for(long long l=k+1;l<=n;l++){
														for(long long o=l+1;o<=n;o++){
															for(long long p=o+1;p<=n;p++){
																for(long long q=p+1;q<=n;q++){
																	for(long long r=q+1;r<=n;r++){
																		for(long long s=r+1;s<=n;s++){
																			for(long long t=s+1;t<=n;t++){
																				for(long long u=t+1;t<=n;t++){
																					for(long long v=u+1;v<=n;v++){
																						for(long long w=v+1;w<=n;w++){
																							x=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k]&a1[o]&a1[p]&a1[q]&a1[r]&a1[s]&a1[t]&a1[u]&a1[v]&a1[w];
																							mx=max(mx,x);
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
							}
						}
					}
				}
			}
		}
	}
	cout<<mx;
	return 0;
}
