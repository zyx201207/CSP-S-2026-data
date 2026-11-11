#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200200],t=0,l,r,num=0,nu=-1;
bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	//cout<<n<<m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=20){
		if(m==1){
			sort(a,a+n,cmp);
			num=a[0];
		}else if(m==2){
			for(long long i=0;i<n;i++){
				for(long long j=i+1;j<n;j++){
					num=max(num,a[i]&a[j]);
				}
			}
		}else if(m==3){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
						num=max(num,a[h]&a[i]&a[j]);
					}
				}
			} 
		}else if(m==4){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								num=max(num,a[h]&a[i]&a[j]&a[k]);
							}
						}
					
				}
			} 
		}else if(m==5){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]);
								}
							}
						}
					
				}
			} 
		}
		else if(m==6){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]);
									}
								}
							
						}
					}
				}
			} 
		}else if(m==7){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]);
										}
									}
								}
							
						}
					}
				}
			} 
		}else if(m==8){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]);
											}
										}
									}
								}
							}
						
					}
				}
			} 
		}else if(m==9){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]);
												}
											}
										}
									}
								}
							}
						
					}
				}
			} 
		}else if(m==10){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													for(long long g=t+1;g<n;g++){
														num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]&a[t]);
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
		}else if(m==11){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													for(long long g=t+1;g<n;g++){
														for(long long re=g+1;re<n;re++){
															num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]&a[t]&a[re]);
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
		}else if(m==12){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													for(long long g=t+1;g<n;g++){
														for(long long re=g+1;re<n;re++){
															for(long long rt=re+1;rt<n;rt++){
																num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]&a[t]&a[re]&a[rt]);
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
		}else if(m==13){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													for(long long g=t+1;g<n;g++){
														for(long long re=g+1;re<n;re++){
															for(long long rt=re+1;rt<n;rt++){
																for(long long rf=rt+1;rf<n;rf++){
																	num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]&a[t]&a[re]&a[rt]&a[rf]);
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
		}else if(m==14){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													for(long long g=t+1;g<n;g++){
														for(long long re=g+1;re<n;re++){
															for(long long rt=re+1;rt<n;rt++){
																for(long long rf=rt+1;rf<n;rf++){
																	for(long long rd=rf+1;rd<n;rd++){
																		num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]&a[t]&a[re]&a[rt]&a[rf]&a[rd]);
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
		}else if(m==15){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													for(long long g=t+1;g<n;g++){
														for(long long re=g+1;re<n;re++){
															for(long long rt=re+1;rt<n;rt++){
																for(long long rf=rt+1;rf<n;rf++){
																	for(long long rd=rf+1;rd<n;rd++){
																		for(long long ri=rd+1;ri<n;ri++){
																			num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]&a[t]&a[re]&a[rt]&a[rf]&a[rd]&a[ri]);
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
		}else if(m==16){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													for(long long g=t+1;g<n;g++){
														for(long long re=g+1;re<n;re++){
															for(long long rt=re+1;rt<n;rt++){
																for(long long rf=rt+1;rf<n;rf++){
																	for(long long rd=rf+1;rd<n;rd++){
																		for(long long ri=rd+1;ri<n;ri++){
																			for(long long rj=ri+1;rj<n;rj++){
																				num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]&a[t]&a[re]&a[rt]&a[rf]&a[rd]&a[ri]&a[rj]);
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
		}else if(m==17){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													for(long long g=t+1;g<n;g++){
														for(long long re=g+1;re<n;re++){
															for(long long rt=re+1;rt<n;rt++){
																for(long long rf=rt+1;rf<n;rf++){
																	for(long long rd=rf+1;rd<n;rd++){
																		for(long long ri=rd+1;ri<n;ri++){
																			for(long long rj=ri+1;rj<n;rj++){
																				for(long long rh=rj+1;rh<n;rh++){
																					num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]&a[t]&a[re]&a[rt]&a[rf]&a[rd]&a[ri]&a[rj]&a[rh]);
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
		}else if(m==18){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													for(long long g=t+1;g<n;g++){
														for(long long re=g+1;re<n;re++){
															for(long long rt=re+1;rt<n;rt++){
																for(long long rf=rt+1;rf<n;rf++){
																	for(long long rd=rf+1;rd<n;rd++){
																		for(long long ri=rd+1;ri<n;ri++){
																			for(long long rj=ri+1;rj<n;rj++){
																				for(long long rh=rj+1;rh<n;rh++){
																					for(long long rg=rh+1;rg<n;rg++){
																						num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]&a[t]&a[re]&a[rt]&a[rf]&a[rd]&a[ri]&a[rj]&a[rh]&a[rg]);
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
		}else if(m==19){
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													for(long long g=t+1;g<n;g++){
														for(long long re=g+1;re<n;re++){
															for(long long rt=re+1;rt<n;rt++){
																for(long long rf=rt+1;rf<n;rf++){
																	for(long long rd=rf+1;rd<n;rd++){
																		for(long long ri=rd+1;ri<n;ri++){
																			for(long long rj=ri+1;rj<n;rj++){
																				for(long long rh=rj+1;rh<n;rh++){
																					for(long long rg=rh+1;rg<n;rg++){
																						for(long long rs=rg+1;rs<n;rs++){
																							num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]&a[t]&a[re]&a[rt]&a[rf]&a[rd]&a[ri]&a[rj]&a[rh]&a[rg]&a[rs]);
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
		}else{
			for(long long h=0;h<n;h++){
				for(long long i=h+1;i<n;i++){
					for(long long j=i+1;j<n;j++){
							for(long long k=j+1;k<n;k++){
								for(long long u=k+1;u<n;u++){
									for(long long q=u+1;q<n;q++){
										for(long long s=q+1;s<n;s++){
											for(long long w=s+1;w<n;w++){
												for(long long t=w+1;t<n;t++){
													for(long long g=t+1;g<n;g++){
														for(long long re=g+1;re<n;re++){
															for(long long rt=re+1;rt<n;rt++){
																for(long long rf=rt+1;rf<n;rf++){
																	for(long long rd=rf+1;rd<n;rd++){
																		for(long long ri=rd+1;ri<n;ri++){
																			for(long long rj=ri+1;rj<n;rj++){
																				for(long long rh=rj+1;rh<n;rh++){
																					for(long long rg=rh+1;rg<n;rg++){
																						for(long long rs=rg+1;rs<n;rs++){
																							for(long long rq=rs+1;rq<n;rq++){
																								num=max(num,a[h]&a[i]&a[j]&a[k]&a[u]&a[q]&a[s]&a[w]&a[t]&a[t]&a[re]&a[rt]&a[rf]&a[rd]&a[ri]&a[rj]&a[rh]&a[rg]&a[rs]&a[rq]);
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
		
		
		
		
		cout<<num;
		
	}else if(n<=2000){
		//cout<<"%%%";
		if(m==1){
			sort(a,a+n,cmp);
			num=a[0];
		}else if(m==n){
			num=a[0];
			for(int i=1;i<n;i++){
				num&=a[i];
			}
		}else if(m==2){
			//cout<<"&&&";
			for(long long i=0;i<n;i++){
				for(long long j=i+1;j<n;j++){
					num=max(num,a[i]&a[j]);
				}
			}
		}
		cout<<num;
	}else{
		if(m==n-1){
			for(long long i=0;i<n;i++){
				for(long long j=0;j<n;j++){
					if(j!=i){
						if(nu==-1){
							nu=a[j];
						}else{
							nu&=a[j];
						}

					}
					
				}
				num=max(num,nu);
			}
			cout<<num;
		}else{
			cout<<rand();
		}
	}
	
	
	
	sort(a,a+n,cmp);
	for(long long i=0;i<n;i++){
		t=0;
		
	}
	fclose(stdin);
	fclose(stdout);
}
