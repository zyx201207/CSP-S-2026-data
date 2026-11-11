#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	unsigned long long n,m;
	cin>>n>>m;
	cin>>a[1];
	unsigned long long s123=a[1],m123=a[1];
	for(unsigned long long i=2;i<=n;i++){
		cin>>a[i];
		s123=(s123&a[i]);
		m123=max(m123,a[i]);
	}
	if(n==m){
		cout<<s123;
		return 0;
	}
	if(m==1){
		cout<<m123;
		return 0;
	}
	if(m==2){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n;i++){
			for(unsigned long long j=i+1;j<=n;j++){
				m=max(m,(a[i]&a[j]));
			}
		}
		cout<<m;
		return 0;
	}
	if(m==3){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-1;i++){
			for(unsigned long long j=i+1;j<n;j++){
				for(unsigned long long k=j+1;k<=n;k++){
					m=max(m,(a[i]&a[j]&a[k]));
				}
			}
		}
		cout<<m;
		return 0;
	}
	if(m==4){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-2;i++){
			for(unsigned long long j=i+1;j<n-1;j++){
				for(unsigned long long k=j+1;k<n;k++){
					for(unsigned long long k1=k+1;k1<=n;k1++){
						m=max(m,(a[i]&a[j]&a[k]&a[k1]));
					}
				}
			}
		}
		cout<<m;
		return 0;
	}
	if(m==5){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-3;i++){
			for(unsigned long long j=i+1;j<n-2;j++){
				for(unsigned long long k=j+1;k<n-1;k++){
					for(unsigned long long k1=k+1;k1<n;k1++){
						for(unsigned long long k2=k1+1;k2<=n;k2++){
							m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]));
						}
					}
				}
			}
		}
		cout<<m;
		return 0;
	}
	if(m==6){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-4;i++){
			for(unsigned long long j=i+1;j<n-3;j++){
				for(unsigned long long k=j+1;k<n-2;k++){
					for(unsigned long long k1=k+1;k1<n-1;k1++){
						for(unsigned long long k2=k1+1;k2<n;k2++){
							for(unsigned long long k3=k2+1;k3<=n;k3++){
								m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]));
							}
						}
					}
				}
			}
		}
		cout<<m;
		return 0;
	}
	if(m==7){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-5;i++){
			for(unsigned long long j=i+1;j<n-4;j++){
				for(unsigned long long k=j+1;k<n-3;k++){
					for(unsigned long long k1=k+1;k1<n-2;k1++){
						for(unsigned long long k2=k1+1;k2<n-1;k2++){
							for(unsigned long long k3=k2+1;k3<n;k3++){
								for(unsigned long long k4=k3+1;k4<=n;k4++){
									m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]));
								}
							}
						}
					}
				}
			}
		}
		cout<<m;
		return 0;
	}
	if(m==8){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-6;i++){
			for(unsigned long long j=i+1;j<n-5;j++){
				for(unsigned long long k=j+1;k<n-4;k++){
					for(unsigned long long k1=k+1;k1<n-3;k1++){
						for(unsigned long long k2=k1+1;k2<n-2;k2++){
							for(unsigned long long k3=k2+1;k3<n-1;k3++){
								for(unsigned long long k4=k3+1;k4<n;k4++){
									for(unsigned long long k5=k4+1;k5<=n;k5++){
										m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]));
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<m;
		return 0;
	}
	if(m==9){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-7;i++){
			for(unsigned long long j=i+1;j<n-6;j++){
				for(unsigned long long k=j+1;k<n-5;k++){
					for(unsigned long long k1=k+1;k1<n-4;k1++){
						for(unsigned long long k2=k1+1;k2<n-3;k2++){
							for(unsigned long long k3=k2+1;k3<n-2;k3++){
								for(unsigned long long k4=k3+1;k4<n-1;k4++){
									for(unsigned long long k5=k4+1;k5<n;k5++){
										for(unsigned long long k6=k5+1;k6<=n;k6++){
											m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]));
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<m;
		return 0;
	}
	if(m==10){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-8;i++){
			for(unsigned long long j=i+1;j<n-7;j++){
				for(unsigned long long k=j+1;k<n-6;k++){
					for(unsigned long long k1=k+1;k1<n-5;k1++){
						for(unsigned long long k2=k1+1;k2<n-4;k2++){
							for(unsigned long long k3=k2+1;k3<n-3;k3++){
								for(unsigned long long k4=k3+1;k4<n-2;k4++){
									for(unsigned long long k5=k4+1;k5<n-1;k5++){
										for(unsigned long long k6=k5+1;k6<n;k6++){
											for(unsigned long long k7=k6+1;k7<=n;k7++){
												m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]));
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
		cout<<m;
		return 0;
	}
	if(m==11){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-9;i++){
			for(unsigned long long j=i+1;j<n-8;j++){
				for(unsigned long long k=j+1;k<n-7;k++){
					for(unsigned long long k1=k+1;k1<n-6;k1++){
						for(unsigned long long k2=k1+1;k2<n-5;k2++){
							for(unsigned long long k3=k2+1;k3<n-4;k3++){
								for(unsigned long long k4=k3+1;k4<n-3;k4++){
									for(unsigned long long k5=k4+1;k5<n-2;k5++){
										for(unsigned long long k6=k5+1;k6<n-1;k6++){
											for(unsigned long long k7=k6+1;k7<n;k7++){
												for(unsigned long long k8=k7+1;k8<=n;k8++){
													m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]));
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
		cout<<m;
		return 0;
	}
	if(m==12){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-10;i++){
			for(unsigned long long j=i+1;j<n-9;j++){
				for(unsigned long long k=j+1;k<n-8;k++){
					for(unsigned long long k1=k+1;k1<n-7;k1++){
						for(unsigned long long k2=k1+1;k2<n-6;k2++){
							for(unsigned long long k3=k2+1;k3<n-5;k3++){
								for(unsigned long long k4=k3+1;k4<n-4;k4++){
									for(unsigned long long k5=k4+1;k5<n-3;k5++){
										for(unsigned long long k6=k5+1;k6<n-2;k6++){
											for(unsigned long long k7=k6+1;k7<n-1;k7++){
												for(unsigned long long k8=k7+1;k8<n;k8++){
													for(unsigned long long k9=k8+1;k9<=n;k9++){
														m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]));
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
		cout<<m;
		return 0;
	}
	if(m==13){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-11;i++){
			for(unsigned long long j=i+1;j<n-10;j++){
				for(unsigned long long k=j+1;k<n-9;k++){
					for(unsigned long long k1=k+1;k1<n-8;k1++){
						for(unsigned long long k2=k1+1;k2<n-7;k2++){
							for(unsigned long long k3=k2+1;k3<n-6;k3++){
								for(unsigned long long k4=k3+1;k4<n-5;k4++){
									for(unsigned long long k5=k4+1;k5<n-4;k5++){
										for(unsigned long long k6=k5+1;k6<n-3;k6++){
											for(unsigned long long k7=k6+1;k7<n-2;k7++){
												for(unsigned long long k8=k7+1;k8<n-1;k8++){
													for(unsigned long long k9=k8+1;k9<n;k9++){
														for(unsigned long long k10=k9+1;k10<=n;k10++){
															m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]));
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
		cout<<m;
		return 0;
	}
	if(m==14){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-12;i++){
			for(unsigned long long j=i+1;j<n-11;j++){
				for(unsigned long long k=j+1;k<n-10;k++){
					for(unsigned long long k1=k+1;k1<n-9;k1++){
						for(unsigned long long k2=k1+1;k2<n-8;k2++){
							for(unsigned long long k3=k2+1;k3<n-7;k3++){
								for(unsigned long long k4=k3+1;k4<n-6;k4++){
									for(unsigned long long k5=k4+1;k5<n-5;k5++){
										for(unsigned long long k6=k5+1;k6<n-4;k6++){
											for(unsigned long long k7=k6+1;k7<n-3;k7++){
												for(unsigned long long k8=k7+1;k8<n-2;k8++){
													for(unsigned long long k9=k8+1;k9<n-1;k9++){
														for(unsigned long long k10=k9+1;k10<n;k10++){
															for(unsigned long long k11=k10+1;k11<=n;k11++){
																m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]));
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
		cout<<m;
		return 0;
	}
	if(m==15){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-13;i++){
			for(unsigned long long j=i+1;j<n-12;j++){
				for(unsigned long long k=j+1;k<n-11;k++){
					for(unsigned long long k1=k+1;k1<n-10;k1++){
						for(unsigned long long k2=k1+1;k2<n-9;k2++){
							for(unsigned long long k3=k2+1;k3<n-8;k3++){
								for(unsigned long long k4=k3+1;k4<n-7;k4++){
									for(unsigned long long k5=k4+1;k5<n-6;k5++){
										for(unsigned long long k6=k5+1;k6<n-5;k6++){
											for(unsigned long long k7=k6+1;k7<n-4;k7++){
												for(unsigned long long k8=k7+1;k8<n-3;k8++){
													for(unsigned long long k9=k8+1;k9<n-2;k9++){
														for(unsigned long long k10=k9+1;k10<n-1;k10++){
															for(unsigned long long k11=k10+1;k11<n;k11++){
																for(unsigned long long k12=k11+1;k12<=n;k12++){
																	m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]));
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
		cout<<m;
		return 0;
	}
	if(m==16){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-14;i++){
			for(unsigned long long j=i+1;j<n-13;j++){
				for(unsigned long long k=j+1;k<n-12;k++){
					for(unsigned long long k1=k+1;k1<n-11;k1++){
						for(unsigned long long k2=k1+1;k2<n-10;k2++){
							for(unsigned long long k3=k2+1;k3<n-9;k3++){
								for(unsigned long long k4=k3+1;k4<n-8;k4++){
									for(unsigned long long k5=k4+1;k5<n-7;k5++){
										for(unsigned long long k6=k5+1;k6<n-6;k6++){
											for(unsigned long long k7=k6+1;k7<n-5;k7++){
												for(unsigned long long k8=k7+1;k8<n-4;k8++){
													for(unsigned long long k9=k8+1;k9<n-3;k9++){
														for(unsigned long long k10=k9+1;k10<n-2;k10++){
															for(unsigned long long k11=k10+1;k11<n-1;k11++){
																for(unsigned long long k12=k11+1;k12<n;k12++){
																	for(unsigned long long k13=k12+1;k13<=n;k13++){
																		m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]&a[k13]));
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
		cout<<m;
		return 0;
	}
	if(m==17){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-15;i++){
			for(unsigned long long j=i+1;j<n-14;j++){
				for(unsigned long long k=j+1;k<n-13;k++){
					for(unsigned long long k1=k+1;k1<n-12;k1++){
						for(unsigned long long k2=k1+1;k2<n-11;k2++){
							for(unsigned long long k3=k2+1;k3<n-10;k3++){
								for(unsigned long long k4=k3+1;k4<n-9;k4++){
									for(unsigned long long k5=k4+1;k5<n-8;k5++){
										for(unsigned long long k6=k5+1;k6<n-7;k6++){
											for(unsigned long long k7=k6+1;k7<n-6;k7++){
												for(unsigned long long k8=k7+1;k8<n-5;k8++){
													for(unsigned long long k9=k8+1;k9<n-4;k9++){
														for(unsigned long long k10=k9+1;k10<n-3;k10++){
															for(unsigned long long k11=k10+1;k11<n-2;k11++){
																for(unsigned long long k12=k11+1;k12<n-1;k12++){
																	for(unsigned long long k13=k12+1;k13<n;k13++){
																		for(unsigned long long k14=k13+1;k14<=n;k14++){
																			m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]&a[k13]&a[k14]));
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
		cout<<m;
		return 0;
	}
	if(m==18){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-16;i++){
			for(unsigned long long j=i+1;j<n-15;j++){
				for(unsigned long long k=j+1;k<n-14;k++){
					for(unsigned long long k1=k+1;k1<n-13;k1++){
						for(unsigned long long k2=k1+1;k2<n-12;k2++){
							for(unsigned long long k3=k2+1;k3<n-11;k3++){
								for(unsigned long long k4=k3+1;k4<n-10;k4++){
									for(unsigned long long k5=k4+1;k5<n-9;k5++){
										for(unsigned long long k6=k5+1;k6<n-8;k6++){
											for(unsigned long long k7=k6+1;k7<n-7;k7++){
												for(unsigned long long k8=k7+1;k8<n-6;k8++){
													for(unsigned long long k9=k8+1;k9<n-5;k9++){
														for(unsigned long long k10=k9+1;k10<n-4;k10++){
															for(unsigned long long k11=k10+1;k11<n-3;k11++){
																for(unsigned long long k12=k11+1;k12<n-2;k12++){
																	for(unsigned long long k13=k12+1;k13<n-1;k13++){
																		for(unsigned long long k14=k13+1;k14<n;k14++){
																			for(unsigned long long k15=k14+1;k15<=n;k15++){
																				m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]&a[k13]&a[k14]&a[k15]));
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
		cout<<m;
		return 0;
	}
	if(m==19){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-17;i++){
			for(unsigned long long j=i+1;j<n-16;j++){
				for(unsigned long long k=j+1;k<n-15;k++){
					for(unsigned long long k1=k+1;k1<n-14;k1++){
						for(unsigned long long k2=k1+1;k2<n-13;k2++){
							for(unsigned long long k3=k2+1;k3<n-12;k3++){
								for(unsigned long long k4=k3+1;k4<n-11;k4++){
									for(unsigned long long k5=k4+1;k5<n-10;k5++){
										for(unsigned long long k6=k5+1;k6<n-9;k6++){
											for(unsigned long long k7=k6+1;k7<n-8;k7++){
												for(unsigned long long k8=k7+1;k8<n-7;k8++){
													for(unsigned long long k9=k8+1;k9<n-6;k9++){
														for(unsigned long long k10=k9+1;k10<n-5;k10++){
															for(unsigned long long k11=k10+1;k11<n-4;k11++){
																for(unsigned long long k12=k11+1;k12<n-3;k12++){
																	for(unsigned long long k13=k12+1;k13<n-2;k13++){
																		for(unsigned long long k14=k13+1;k14<n-1;k14++){
																			for(unsigned long long k15=k14+1;k15<n;k15++){
																				for(unsigned long long k16=k15+1;k16<n;k16++){
																					m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]&a[k13]&a[k14]&a[k15]&a[k16]));
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
		cout<<m;
		return 0;
	}
	if(m==20){
		unsigned long long m=0;
		for(unsigned long long i=1;i<n-18;i++){
			for(unsigned long long j=i+1;j<n-17;j++){
				for(unsigned long long k=j+1;k<n-16;k++){
					for(unsigned long long k1=k+1;k1<n-15;k1++){
						for(unsigned long long k2=k1+1;k2<n-14;k2++){
							for(unsigned long long k3=k2+1;k3<n-13;k3++){
								for(unsigned long long k4=k3+1;k4<n-12;k4++){
									for(unsigned long long k5=k4+1;k5<n-11;k5++){
										for(unsigned long long k6=k5+1;k6<n-10;k6++){
											for(unsigned long long k7=k6+1;k7<n-9;k7++){
												for(unsigned long long k8=k7+1;k8<n-8;k8++){
													for(unsigned long long k9=k8+1;k9<n-7;k9++){
														for(unsigned long long k10=k9+1;k10<n-6;k10++){
															for(unsigned long long k11=k10+1;k11<n-5;k11++){
																for(unsigned long long k12=k11+1;k12<n-4;k12++){
																	for(unsigned long long k13=k12+1;k13<n-3;k13++){
																		for(unsigned long long k14=k13+1;k14<n-2;k14++){
																			for(unsigned long long k15=k14+1;k15<n-1;k15++){
																				for(unsigned long long k16=k15+1;k16<n;k16++){
																					for(unsigned long long k17=k16+1;k17<=n;k17++){
																						m=max(m,(a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]&a[k13]&a[k14]&a[k15]&a[k16]&a[k17]));
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
		cout<<m;
		return 0;
	}
	return 0;
}
