#include<bits/stdc++.h>
using namespace std;
int  main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b,max1=0;
	cin>>a>>b;
 	long long c[a];
 	for(long long i=0;i<a;i++){
 		cin>>c[i];
	 }
	if(b==2){
		for(long long i=1;i<a;i++){
			for(long long i1=0;i1<i;i1++){
				max1=max(max1,(c[i] & c[i1]));
			}
		}
	}else if(b==3){
		for(long long i=2;i<a;i++){
			for(long long i1=1;i1<i;i1++){
				for(long long i2=0;i2<i1;i2++){
				max1=max(max1,(c[i] & c[i1] & c[i2]));
				}
			}
		}
	}else if(b==4){
		for(long long i=3;i<a;i++){
			for(long long i1=2;i1<i;i1++){
				for(long long i2=1;i2<i1;i2++){
					for(long long i3=0;i3<i2;i3++){
						max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3]));
					}
				}
			}
		}
	}else if(b==5){
		for(long long i=4;i<a;i++){
			for(long long i1=3;i1<i;i1++){
				for(long long i2=2;i2<i1;i2++){
					for(long long i3=1;i3<i2;i3++){
						for(long long i4=0;i4<i3;i4++){
							max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4])); 
						}
					}
				}
			}
		}
	}else if(b==6){
		for(long long i=5;i<a;i++){
			for(long long i1=4;i1<i;i1++){
				for(long long i2=3;i2<i1;i2++){
					for(long long i3=2;i3<i2;i3++){
						for(long long i4=1;i4<i3;i4++){
							for(long long i5=0;i5<i4;i5++){
								max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5]));
							}
						}
					}
				}
			}
		}
	}else if(b==7){
		for(long long i=6;i<a;i++){
			for(long long i1=5;i1<i;i1++){
				for(long long i2=4;i2<i1;i2++){
					for(long long i3=3;i3<i2;i3++){
						for(long long i4=2;i4<i3;i4++){
							for(long long i5=1;i5<i4;i5++){
								for(long long i6=0;i6<i5;i6++){
								max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6]));
								}
							}
						}
					}
				}
			}
		}
	}else if(b==8){
		for(long long i=7;i<a;i++){
			for(long long i1=6;i1<i;i1++){
				for(long long i2=5;i2<i1;i2++){
					for(long long i3=4;i3<i2;i3++){
						for(long long i4=3;i4<i3;i4++){
							for(long long i5=2;i5<i4;i5++){
								for(long long i6=1;i6<i5;i6++){
									for(long long i7=0;i7<i6;i7++){
										max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7]));
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==9){
		for(long long i=8;i<a;i++){
			for(long long i1=7;i1<i;i1++){
				for(long long i2=6;i2<i1;i2++){
					for(long long i3=5;i3<i2;i3++){
						for(long long i4=4;i4<i3;i4++){
							for(long long i5=3;i5<i4;i5++){
								for(long long i6=2;i6<i5;i6++){
									for(long long i7=1;i7<i6;i7++){
										for(long long i8=0;i8<i7;i8++){
										max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8]));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==10){
		for(long long i=9;i<a;i++){
			for(long long i1=8;i1<i;i1++){
				for(long long i2=7;i2<i1;i2++){
					for(long long i3=6;i3<i2;i3++){
						for(long long i4=5;i4<i3;i4++){
							for(long long i5=4;i5<i4;i5++){
								for(long long i6=3;i6<i5;i6++){
									for(long long i7=2;i7<i6;i7++){
										for(long long i8=1;i8<i7;i8++){
											for(long long i9=0;i9<i8;i9++){
												max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8] & c[i9]));
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==11){
		for(long long i=10;i<a;i++){
			for(long long i1=9;i1<i;i1++){
				for(long long i2=8;i2<i1;i2++){
					for(long long i3=7;i3<i2;i3++){
						for(long long i4=6;i4<i3;i4++){
							for(long long i5=5;i5<i4;i5++){
								for(long long i6=4;i6<i5;i6++){
									for(long long i7=3;i7<i6;i7++){
										for(long long i8=2;i8<i7;i8++){
											for(long long i9=1;i9<i8;i9++){
												for(long long i10=0;i10<i9;i10++){
													max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8] & c[i9] & c[i10]));
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==12){
		for(long long i=11;i<a;i++){
			for(long long i1=10;i1<i;i1++){
				for(long long i2=9;i2<i1;i2++){
					for(long long i3=8;i3<i2;i3++){
						for(long long i4=7;i4<i3;i4++){
							for(long long i5=6;i5<i4;i5++){
								for(long long i6=5;i6<i5;i6++){
									for(long long i7=4;i7<i6;i7++){
										for(long long i8=3;i8<i7;i8++){
											for(long long i9=2;i9<i8;i9++){
												for(long long i10=1;i10<i9;i10++){
													for(long long i11=0;i11<i10;i11++){
														max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8] & c[i9] & c[i10] & c[i11]));
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==13){
		for(long long i=12;i<a;i++){
			for(long long i1=11;i1<i;i1++){
				for(long long i2=10;i2<i1;i2++){
					for(long long i3=9;i3<i2;i3++){
						for(long long i4=8;i4<i3;i4++){
							for(long long i5=7;i5<i4;i5++){
								for(long long i6=6;i6<i5;i6++){
									for(long long i7=5;i7<i6;i7++){
										for(long long i8=4;i8<i7;i8++){
											for(long long i9=3;i9<i8;i9++){
												for(long long i10=2;i10<i9;i10++){
													for(long long i11=1;i11<i10;i11++){
														for(long long i12=0;i12<i11;i12++){
															max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8] & c[i9] & c[i10] & c[i11] & c[i12]));
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==14){
		for(long long i=13;i<a;i++){
			for(long long i1=12;i1<i;i1++){
				for(long long i2=11;i2<i1;i2++){
					for(long long i3=10;i3<i2;i3++){
						for(long long i4=9;i4<i3;i4++){
							for(long long i5=8;i5<i4;i5++){
								for(long long i6=7;i6<i5;i6++){
									for(long long i7=6;i7<i6;i7++){
										for(long long i8=5;i8<i7;i8++){
											for(long long i9=4;i9<i8;i9++){
												for(long long i10=3;i10<i9;i10++){
													for(long long i11=2;i11<i10;i11++){
														for(long long i12=1;i12<i11;i12++){
															for(long long i13=0;i13<i12;i13++){
																max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8] & c[i9] & c[i10] & c[i11] & c[i12] & c[i13]));
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==15){
		for(long long i=14;i<a;i++){
			for(long long i1=13;i1<i;i1++){
				for(long long i2=12;i2<i1;i2++){
					for(long long i3=11;i3<i2;i3++){
						for(long long i4=10;i4<i3;i4++){
							for(long long i5=9;i5<i4;i5++){
								for(long long i6=8;i6<i5;i6++){
									for(long long i7=7;i7<i6;i7++){
										for(long long i8=6;i8<i7;i8++){
											for(long long i9=5;i9<i8;i9++){
												for(long long i10=4;i10<i9;i10++){
													for(long long i11=3;i11<i10;i11++){
														for(long long i12=2;i12<i11;i12++){
															for(long long i13=1;i13<i12;i13++){
																for(long long i14=0;i14<i13;i14++){
																	max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8] & c[i9] & c[i10] & c[i11] & c[i12] & c[i13] &c[i14]));
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==16){
		for(long long i=15;i<a;i++){
			for(long long i1=14;i1<i;i1++){
				for(long long i2=13;i2<i1;i2++){
					for(long long i3=12;i3<i2;i3++){
						for(long long i4=11;i4<i3;i4++){
							for(long long i5=10;i5<i4;i5++){
								for(long long i6=9;i6<i5;i6++){
									for(long long i7=8;i7<i6;i7++){
										for(long long i8=7;i8<i7;i8++){
											for(long long i9=6;i9<i8;i9++){
												for(long long i10=5;i10<i9;i10++){
													for(long long i11=4;i11<i10;i11++){
														for(long long i12=3;i12<i11;i12++){
															for(long long i13=2;i13<i12;i13++){
																for(long long i14=1;i14<i13;i14++){
																	for(long long i15=0;i15<i14;i15++){
																		max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8] & c[i9] & c[i10] & c[i11] & c[i12] & c[i13] & c[i14] & c[i15]));
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==17){
		for(long long i=16;i<a;i++){
			for(long long i1=15;i1<i;i1++){
				for(long long i2=14;i2<i1;i2++){
					for(long long i3=13;i3<i2;i3++){
						for(long long i4=12;i4<i3;i4++){
							for(long long i5=11;i5<i4;i5++){
								for(long long i6=10;i6<i5;i6++){
									for(long long i7=9;i7<i6;i7++){
										for(long long i8=8;i8<i7;i8++){
											for(long long i9=7;i9<i8;i9++){
												for(long long i10=6;i10<i9;i10++){
													for(long long i11=5;i11<i10;i11++){
														for(long long i12=4;i12<i11;i12++){
															for(long long i13=3;i13<i12;i13++){
																for(long long i14=2;i14<i13;i14++){
																	for(long long i15=1;i15<i14;i15++){
																		for(long long i16=0;i16<i15;i16++){
																			max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8] & c[i9] & c[i10] & c[i11] & c[i12] & c[i13] & c[i14] & c[i15] & c[i16]));
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==18){
		for(long long i=17;i<a;i++){
			for(long long i1=16;i1<i;i1++){
				for(long long i2=15;i2<i1;i2++){
					for(long long i3=14;i3<i2;i3++){
						for(long long i4=13;i4<i3;i4++){
							for(long long i5=12;i5<i4;i5++){
								for(long long i6=11;i6<i5;i6++){
									for(long long i7=10;i7<i6;i7++){
										for(long long i8=9;i8<i7;i8++){
											for(long long i9=8;i9<i8;i9++){
												for(long long i10=7;i10<i9;i10++){
													for(long long i11=6;i11<i10;i11++){
														for(long long i12=5;i12<i11;i12++){
															for(long long i13=4;i13<i12;i13++){
																for(long long i14=3;i14<i13;i14++){
																	for(long long i15=2;i15<i14;i15++){
																		for(long long i16=1;i16<i15;i16++){
																			for(long long i17=1;i17<i16;i17++){
																				max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8] & c[i9] & c[i10] & c[i11] & c[i12] & c[i13] & c[i14] & c[i15] & c[i16] & c[i17]));
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==19){
		for(long long i=18;i<a;i++){
			for(long long i1=17;i1<i;i1++){
				for(long long i2=16;i2<i1;i2++){
					for(long long i3=15;i3<i2;i3++){
						for(long long i4=14;i4<i3;i4++){
							for(long long i5=13;i5<i4;i5++){
								for(long long i6=12;i6<i5;i6++){
									for(long long i7=11;i7<i6;i7++){
										for(long long i8=10;i8<i7;i8++){
											for(long long i9=9;i9<i8;i9++){
												for(long long i10=8;i10<i9;i10++){
													for(long long i11=7;i11<i10;i11++){
														for(long long i12=6;i12<i11;i12++){
															for(long long i13=5;i13<i12;i13++){
																for(long long i14=4;i14<i13;i14++){
																	for(long long i15=3;i15<i14;i15++){
																		for(long long i16=2;i16<i15;i16++){
																			for(long long i17=1;i17<i16;i17++){
																				for(long long i18=0;i18<i17;i18++){
																					max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8] & c[i9] & c[i10] & c[i11] & c[i12] & c[i13] & c[i14] & c[i15] & c[i16] & c[i17] & c[i18]));
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(b==20){
		for(long long i=19;i<a;i++){
			for(long long i1=18;i1<i;i1++){
				for(long long i2=17;i2<i1;i2++){
					for(long long i3=16;i3<i2;i3++){
						for(long long i4=15;i4<i3;i4++){
							for(long long i5=14;i5<i4;i5++){
								for(long long i6=13;i6<i5;i6++){
									for(long long i7=12;i7<i6;i7++){
										for(long long i8=11;i8<i7;i8++){
											for(long long i9=10;i9<i8;i9++){
												for(long long i10=9;i10<i9;i10++){
													for(long long i11=8;i11<i10;i11++){
														for(long long i12=7;i12<i11;i12++){
															for(long long i13=6;i13<i12;i13++){
																for(long long i14=5;i14<i13;i14++){
																	for(long long i15=4;i15<i14;i15++){
																		for(long long i16=3;i16<i15;i16++){
																			for(long long i17=2;i17<i16;i17++){
																				for(long long i18=1;i18<i17;i18++){
																					for(long long i19=0;i19<i18;i19++){
																						max1=max(max1,(c[i] & c[i1] & c[i2] & c[i3] & c[i4] & c[i5] & c[i6] & c[i7] & c[i8] & c[i9] & c[i10] & c[i11] & c[i12] & c[i13] & c[i14] & c[i15] & c[i16] & c[i17] & c[i18] &c[i19]));
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<max1;
	return 0;
}
