#include<bits/stdc++.h>
using namespace std;
int n,b,a[201000],maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(b==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(b==2){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]&a[i+1]);
		}
	}
	if(b==3){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]&a[j+1]);
			}
		}
	}
	if(b==4){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
						maxx=max(maxx,a[i]&a[j]&a[k]&a[k+1]);
				}
			}
		}
	}	
	if(b==5){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[y+1]);	
					}
				}
			}
		}
	}
	if(b==6){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[z+1]);
						}
					}
				}
			}
		}
	}
	if(b==7){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i1+1]);
							}
						}
					}
				}
			}
		}
	}
	if(b==8){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=z;i2<=n;i2++){
									maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i2+1]);
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==9){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i3+1]);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==10){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i4+1]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==11){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											for(int i5=i3;i5<=n;i5++){
												maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i5+1]);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==12){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											for(int i5=i4;i5<=n;i5++){
												for(int i6=i5;i6<=n;i6++){
													maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i6+1]);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==13){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											for(int i5=i4;i5<=n;i5++){
												for(int i6=i5;i6<=n;i6++){
													for(int i7=i6;i7<=n;i7++){
														maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i7+1]);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==13){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											for(int i5=i4;i5<=n;i5++){
												for(int i6=i5;i6<=n;i6++){
													for(int i7=i6;i7<=n;i7++){
														for(int i8=i7;i8<=n;i8++){
															maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i8+1]);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==14){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											for(int i5=i4;i5<=n;i5++){
												for(int i6=i5;i6<=n;i6++){
													for(int i7=i6;i7<=n;i7++){
														for(int i8=i7;i8<=n;i8++){
															for(int i9=i8;i9<=n;i9++){
																maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i9+1]);
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==15){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											for(int i5=i4;i5<=n;i5++){
												for(int i6=i5;i6<=n;i6++){
													for(int i7=i6;i7<=n;i7++){
														for(int i8=i7;i8<=n;i8++){
															for(int i9=i8;i9<=n;i9++){
																for(int i10=i9;i10<=n;i10++){
																	maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i10+1]);
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==16){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											for(int i5=i4;i5<=n;i5++){
												for(int i6=i5;i6<=n;i6++){
													for(int i7=i6;i7<=n;i7++){
														for(int i8=i7;i8<=n;i8++){
															for(int i9=i8;i9<=n;i9++){
																for(int i10=i9;i10<=n;i10++){
																	for(int i11=i10;i11<=n;i11++){
																		maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i11+1]);
																	}
																}																		
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==17){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											for(int i5=i4;i5<=n;i5++){
												for(int i6=i5;i6<=n;i6++){
													for(int i7=i6;i7<=n;i7++){
														for(int i8=i7;i8<=n;i8++){
															for(int i9=i8;i9<=n;i9++){
																for(int i10=i9;i10<=n;i10++){
																	for(int i11=i10;i11<=n;i11++){
																		for(int i12=i11;i12<=n;i12++){
																			maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i12+1]);
																		}
																	}
																}																		
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==18){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											for(int i5=i4;i5<=n;i5++){
												for(int i6=i5;i6<=n;i6++){
													for(int i7=i6;i7<=n;i7++){
														for(int i8=i7;i8<=n;i8++){
															for(int i9=i8;i9<=n;i9++){
																for(int i10=i9;i10<=n;i10++){
																	for(int i11=i10;i11<=n;i11++){
																		for(int i12=i11;i12<=n;i12++){
																			for(int i13=i12;i13<=n;i13++){
																				maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i13+1]);
																			}
																		}
																	}
																}																		
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==19){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											for(int i5=i4;i5<=n;i5++){
												for(int i6=i5;i6<=n;i6++){
													for(int i7=i6;i7<=n;i7++){
														for(int i8=i7;i8<=n;i8++){
															for(int i9=i8;i9<=n;i9++){
																for(int i10=i9;i10<=n;i10++){
																	for(int i11=i10;i11<=n;i11++){
																		for(int i12=i11;i12<=n;i12++){
																			for(int i13=i12;i13<=n;i13++){
																				for(int i14=i13;i14<=n;i14++){
																					maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i14+1]);
																				}
																			}
																		}
																	}
																}																		
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==20){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int y=k;y<=n;y++){
						for(int z=y;z<=n;z++){
							for(int i1=z;i1<=n;i1++){
								for(int i2=i1;i2<=n;i2++){
									for(int i3=i2;i3<=n;i3++){
										for(int i4=i3;i4<=n;i4++){
											for(int i5=i4;i5<=n;i5++){
												for(int i6=i5;i6<=n;i6++){
													for(int i7=i6;i7<=n;i7++){
														for(int i8=i7;i8<=n;i8++){
															for(int i9=i8;i9<=n;i9++){
																for(int i10=i9;i10<=n;i10++){
																	for(int i11=i10;i11<=n;i11++){
																		for(int i12=i11;i12<=n;i12++){
																			for(int i13=i12;i13<=n;i13++){
																				for(int i14=i13;i14<=n;i14++){
																					for(int i15=i14;i15<=n;i15++){
																						maxx=max(maxx,a[i]&a[j]&a[k]&a[y]&a[z]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]&a[i15+1]);
																					}
																				}
																			}
																		}
																	}
																}																		
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}	
	cout<<maxx;
	return 0;
}
