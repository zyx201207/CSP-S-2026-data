#include<bits/stdc++.h>
using namespace std;
long long a[210000];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n<=20) {
		long long ans=0;
		if(m==1) {
			for(int i1=1; i1<=n; i1++) {
				ans=max(ans,a[i1]);
			}
		}
		if(m==2) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					ans=max(ans,a[i1]&a[i2]);
				}
			}
		}
		if(m==3) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						ans=max(ans,a[i2]&a[i1]&a[i3]);
					}
				}
			}
		}
		if(m==4) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]);
						}
					}
				}
			}
		}
		if(m==5) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]);
							}
						}
					}
				}
			}
		}
		if(m==6) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]);
								}
							}
						}
					}
				}
			}
		}
		if(m==7) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]);
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==8) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]);
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
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {

												ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]);
											}
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
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {
												for(int i10=i9+1; i10<=n; i10++) {
													ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==11) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {
												for(int i10=i9+1; i10<=n; i10++) {
													for(int i11=i10+1; i11<=n; i11++) {

														ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==12) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {
												for(int i10=i9+1; i10<=n; i10++) {
													for(int i11=i10+1; i11<=n; i11++) {
														for(int i12=i11+1; i12<=n; i12++) {

															ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==13) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {
												for(int i10=i9+1; i10<=n; i10++) {
													for(int i11=i10+1; i11<=n; i11++) {
														for(int i12=i11+1; i12<=n; i12++) {
															for(int i13=i12+1; i13<=n; i13++) {

																ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]);
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==14) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {
												for(int i10=i9+1; i10<=n; i10++) {
													for(int i11=i10+1; i11<=n; i11++) {
														for(int i12=i11+1; i12<=n; i12++) {
															for(int i13=i12+1; i13<=n; i13++) {
																for(int i14=i13+1; i14<=n; i14++) {

																	ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]);
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==15) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {
												for(int i10=i9+1; i10<=n; i10++) {
													for(int i11=i10+1; i11<=n; i11++) {
														for(int i12=i11+1; i12<=n; i12++) {
															for(int i13=i12+1; i13<=n; i13++) {
																for(int i14=i13+1; i14<=n; i14++) {
																	for(int i15=i14+1; i15<=n; i15++) {

																		ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==16) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {
												for(int i10=i9+1; i10<=n; i10++) {
													for(int i11=i10+1; i11<=n; i11++) {
														for(int i12=i11+1; i12<=n; i12++) {
															for(int i13=i12+1; i13<=n; i13++) {
																for(int i14=i13+1; i14<=n; i14++) {
																	for(int i15=i14+1; i15<=n; i15++) {
																		for(int i16=i15+1; i16<=n; i16++) {

																			ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]&a[i16]);
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==17) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {
												for(int i10=i9+1; i10<=n; i10++) {
													for(int i11=i10+1; i11<=n; i11++) {
														for(int i12=i11+1; i12<=n; i12++) {
															for(int i13=i12+1; i13<=n; i13++) {
																for(int i14=i13+1; i14<=n; i14++) {
																	for(int i15=i14+1; i15<=n; i15++) {
																		for(int i16=i15+1; i16<=n; i16++) {
																			for(int i17=i16+1; i17<=n; i17++) {

																				ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]&a[i16]&a[i17]);
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==18) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {
												for(int i10=i9+1; i10<=n; i10++) {
													for(int i11=i10+1; i11<=n; i11++) {
														for(int i12=i11+1; i12<=n; i12++) {
															for(int i13=i12+1; i13<=n; i13++) {
																for(int i14=i13+1; i14<=n; i14++) {
																	for(int i15=i14+1; i15<=n; i15++) {
																		for(int i16=i15+1; i16<=n; i16++) {
																			for(int i17=i16+1; i17<=n; i17++) {
																				for(int i18=i17+1; i18<=n; i18++) {

																					ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]&a[i16]&a[i17]&a[i18]);
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==19) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {
												for(int i10=i9+1; i10<=n; i10++) {
													for(int i11=i10+1; i11<=n; i11++) {
														for(int i12=i11+1; i12<=n; i12++) {
															for(int i13=i12+1; i13<=n; i13++) {
																for(int i14=i13+1; i14<=n; i14++) {
																	for(int i15=i14+1; i15<=n; i15++) {
																		for(int i16=i15+1; i16<=n; i16++) {
																			for(int i17=i16+1; i17<=n; i17++) {
																				for(int i18=i17+1; i18<=n; i18++) {
																					for(int i19=i18+1; i19<=n; i19++) {

																						ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]&a[i16]&a[i17]&a[i18]&a[i19]);
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(m==20) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					for(int i3=i2+1; i3<=n; i3++) {
						for(int i4=i3+1; i4<=n; i4++) {
							for(int i5=i4+1; i5<=n; i5++) {
								for(int i6=i5+1; i6<=n; i6++) {
									for(int i7=i6+1; i7<=n; i7++) {
										for(int i8=i7+1; i8<=n; i8++) {
											for(int i9=i8+1; i9<=n; i9++) {
												for(int i10=i9+1; i10<=n; i10++) {
													for(int i11=i10+1; i11<=n; i11++) {
														for(int i12=i11+1; i12<=n; i12++) {
															for(int i13=i12+1; i13<=n; i13++) {
																for(int i14=i13+1; i14<=n; i14++) {
																	for(int i15=i14+1; i15<=n; i15++) {
																		for(int i16=i15+1; i16<=n; i16++) {
																			for(int i17=i16+1; i17<=n; i17++) {
																				for(int i18=i17+1; i18<=n; i18++) {
																					for(int i19=i18+1; i19<=n; i19++) {
																						for(int i20=i19+1; i20<=n; i20++) {

																							ans=max(ans,a[i2]&a[i1]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]&a[i16]&a[i17]&a[i18]&a[i19]&a[i20]);
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	} else {
		long long ans=0;
		if(m==1) {
			for(int i=1; i<=n; i++)ans=max(ans,a[i]);
		} else if(m==n) {
			ans=a[1];
			for(int i=2; i<=n; i++)ans=ans&a[i];
		} else if(m==2) {
			for(int i1=1; i1<=n; i1++) {
				for(int i2=i1+1; i2<=n; i2++) {
					ans=max(ans,a[i1]&a[i2]);
				}
			}
		}
		else if(m==n-1){
			ans=a[1];
			for(int i=2; i<=n; i++)ans=ans&a[i];
			for(int i=1;i<=n;i++){
				long long k=ans;
				k=k&(~a[i]);
				ans=max(k,ans);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
