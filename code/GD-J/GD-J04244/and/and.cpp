#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+3];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=-1;
	sort(a+1,a+1+n);
	if(m==1){
		for(int i=1;i<=n;i++){
			if(k<a[i])k=a[i];
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				k=max(a[i]&a[j],k);
			}
		}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int d=j+1;d<=n;d++){
					if(a[i]&a[j]&a[d]>k)k=a[i]&a[j]&a[d];
				}
			}
		}
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						if(a[i]&a[j]&a[c]&a[d]>k)k=a[i]&a[j]&a[c]&a[d];
					}
				}
			}
		}
	}
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							k=max(a[i]&a[j]&a[c]&a[d]&a[a1],k);
						}
					}
				}
			}
		}
	}
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2],k);
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
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3],k);
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
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4],k);
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
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5],k);
										}
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
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											for(int a6=a5+1;a6<=n;a6++){
												k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6],k);
											}
										}
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
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											for(int a6=a5+1;a6<=n;a6++){
												for(int a7=a6+1;a7<=n;a7++){
													k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6]&a[a7],k);
												}
											}
										}
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
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											for(int a6=a5+1;a6<=n;a6++){
												for(int a7=a6+1;a7<=n;a7++){
													for(int a8=a7+1;a8<=n;a8++){
														k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6]&a[a7]&a[a8],k);
													}
												}
											}
										}
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
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											for(int a6=a5+1;a6<=n;a6++){
												for(int a7=a6+1;a7<=n;a7++){
													for(int a8=a7+1;a8<=n;a8++){
														for(int a9=a8+1;a9<=n;a9++){
															k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6]&a[a7]&a[a8]&a[a9],k);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(m==14){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											for(int a6=a5+1;a6<=n;a6++){
												for(int a7=a6+1;a7<=n;a7++){
													for(int a8=a7+1;a8<=n;a8++){
														for(int a9=a8+1;a9<=n;a9++){
															for(int a10=a9+1;a10<=n;a10++){
																k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6]&a[a7]&a[a8]&a[a9]&a[a10],k);
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(m==15){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											for(int a6=a5+1;a6<=n;a6++){
												for(int a7=a6+1;a7<=n;a7++){
													for(int a8=a7+1;a8<=n;a8++){
														for(int a9=a8+1;a9<=n;a9++){
															for(int a10=a9+1;a10<=n;a10++){
																for(int a11=a10+1;a11<=n;a11++){
																	k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6]&a[a7]&a[a8]&a[a9]&a[a10]&a[a11],k);
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}if(m==16){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											for(int a6=a5+1;a6<=n;a6++){
												for(int a7=a6+1;a7<=n;a7++){
													for(int a8=a7+1;a8<=n;a8++){
														for(int a9=a8+1;a9<=n;a9++){
															for(int a10=a9+1;a10<=n;a10++){
																for(int a11=a10+1;a11<=n;a11++){
																	for(int a12=a11+1;a12<=n;a12++){
																		k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6]&a[a7]&a[a8]&a[a9]&a[a10]&a[a11]&a[a12],k);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(m==17){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											for(int a6=a5+1;a6<=n;a6++){
												for(int a7=a6+1;a7<=n;a7++){
													for(int a8=a7+1;a8<=n;a8++){
														for(int a9=a8+1;a9<=n;a9++){
															for(int a10=a9+1;a10<=n;a10++){
																for(int a11=a10+1;a11<=n;a11++){
																	for(int a12=a11+1;a12<=n;a12++){
																		for(int a13=a12+1;a13<=n;a13++){
																			k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6]&a[a7]&a[a8]&a[a9]&a[a10]&a[a11]&a[a12]&a[a13],k);
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(m==18){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											for(int a6=a5+1;a6<=n;a6++){
												for(int a7=a6+1;a7<=n;a7++){
													for(int a8=a7+1;a8<=n;a8++){
														for(int a9=a8+1;a9<=n;a9++){
															for(int a10=a9+1;a10<=n;a10++){
																for(int a11=a10+1;a11<=n;a11++){
																	for(int a12=a11+1;a12<=n;a12++){
																		for(int a13=a12+1;a13<=n;a13++){
																			for(int a14=a13+1;a14<=n;a14++){
																				k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6]&a[a7]&a[a8]&a[a9]&a[a10]&a[a11]&a[a12]&a[a13]&a[a14],k);
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(m==19){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											for(int a6=a5+1;a6<=n;a6++){
												for(int a7=a6+1;a7<=n;a7++){
													for(int a8=a7+1;a8<=n;a8++){
														for(int a9=a8+1;a9<=n;a9++){
															for(int a10=a9+1;a10<=n;a10++){
																for(int a11=a10+1;a11<=n;a11++){
																	for(int a12=a11+1;a12<=n;a12++){
																		for(int a13=a12+1;a13<=n;a13++){
																			for(int a14=a13+1;a14<=n;a14++){
																				for(int a15=a14+1;a15<=n;a15++){
																					k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6]&a[a7]&a[a8]&a[a9]&a[a10]&a[a11]&a[a12]&a[a13]&a[a14]&a[a15],k);
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(m==20){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int c=j+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
						for(int a1=d+1;a1<=n;a1++){
							for(int a2=a1+1;a2<=n;a2++){
								for(int a3=a2+1;a3<=n;a3++){
									for(int a4=a3+1;a4<=n;a4++){
										for(int a5=a4+1;a5<=n;a5++){
											for(int a6=a5+1;a6<=n;a6++){
												for(int a7=a6+1;a7<=n;a7++){
													for(int a8=a7+1;a8<=n;a8++){
														for(int a9=a8+1;a9<=n;a9++){
															for(int a10=a9+1;a10<=n;a10++){
																for(int a11=a10+1;a11<=n;a11++){
																	for(int a12=a11+1;a12<=n;a12++){
																		for(int a13=a12+1;a13<=n;a13++){
																			for(int a14=a13+1;a14<=n;a14++){
																				for(int a15=a14+1;a15<=n;a15++){
																					for(int a16=a15+1;a16<=n;a16++){
																						k=max(a[i]&a[j]&a[c]&a[d]&a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6]&a[a7]&a[a8]&a[a9]&a[a10]&a[a11]&a[a12]&a[a13]&a[a14]&a[a15]&a[a16],k);
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<k;
	return 0;
}
