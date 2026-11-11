#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long ma=INT_MIN;
long long t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	if(m==1) cout<<ma;
	else if(m==2){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,(a[i]&a[j]));
			}
		}
		cout<<ma;
	}else if(m==n){
		t=a[1];
		for(int i=2;i<=n;i++){
			t=a[i]&t;
		}
		cout<<t;
	}else if(m==3){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ma=max(ma,(a[i]&a[j]&a[k]));
				}
			}
		}
		cout<<ma;
	}else if(m==4){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
							ma=max(ma,(a[i]&a[j]&a[k]&a[l]));
					}
				}
			}
		}
		cout<<ma;
	}else if(m==5){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]));
						}
					}
				}
			}
		}
		cout<<ma;
	}else if(m==6){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]));
							}
						}
					}
				}
			}
		}
		cout<<ma;
	}else if(m==7){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]));
								}
							}
						}
					}
				}
			}
		}
		cout<<ma;
	}else if(m==8){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]));
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ma;
	}else if(m==9){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]));
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
	}else if(m==10){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											for(int x=z+1;x<=n;x++){
												ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]&a[x]));
											}
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
	}else if(m==11){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											for(int x=z+1;x<=n;x++){
												for(int y=x+1;y<=n;y++){
													ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]&a[x]&a[y]));
												}
											}
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
	}else if(m==12){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											for(int x=z+1;x<=n;x++){
												for(int y=x+1;y<=n;y++){
			   										for(int v=y+1;v<=n;v++){
														ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]&a[x]&a[y]&a[v]));
													}
												}
											}
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
	}else if(m==13){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											for(int x=z+1;x<=n;x++){
												for(int y=x+1;y<=n;y++){
			   										for(int v=y+1;v<=n;v++){
														for(int f=v+1;f<=n;f++){
															ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]&a[x]&a[y]&a[v]&a[f]));
														}
													}
												}
											}
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
	}else if(m==14){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											for(int x=z+1;x<=n;x++){
												for(int y=x+1;y<=n;y++){
			   										for(int v=y+1;v<=n;v++){
														for(int f=v+1;f<=n;f++){
															for(int h=f+1;h<=n;h++){
																ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]&a[x]&a[y]&a[v]&a[f]&a[h]));
															}
														}
													}
												}
											}
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
	}else if(m==15){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											for(int x=z+1;x<=n;x++){
												for(int y=x+1;y<=n;y++){
			   										for(int v=y+1;v<=n;v++){
														for(int f=v+1;f<=n;f++){
															for(int h=f+1;h<=n;h++){
																for(int d=h+1;d<=n;d++){
																	ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]&a[x]&a[y]&a[v]&a[f]&a[h]&a[d]));
																}
															}
														}
													}
												}
											}
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
	}else if(m==16){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											for(int x=z+1;x<=n;x++){
												for(int y=x+1;y<=n;y++){
			   										for(int v=y+1;v<=n;v++){
														for(int f=v+1;f<=n;f++){
															for(int h=f+1;h<=n;h++){
																for(int d=h+1;d<=n;d++){
																	for(int g=d+1;g<=n;g++){
																		ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]&a[x]&a[y]&a[v]&a[f]&a[h]&a[d]&a[g]));
																	}
																}
															}
														}
													}
												}
											}
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
	}else if(m==17){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											for(int x=z+1;x<=n;x++){
												for(int y=x+1;y<=n;y++){
			   										for(int v=y+1;v<=n;v++){
														for(int f=v+1;f<=n;f++){
															for(int h=f+1;h<=n;h++){
																for(int d=h+1;d<=n;d++){
																	for(int g=d+1;g<=n;g++){
																		for(int r=g+1;r<=n;r++){
																			ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]&a[x]&a[y]&a[v]&a[f]&a[h]&a[d]&a[g]&a[r]));
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	}else if(m==18){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											for(int x=z+1;x<=n;x++){
												for(int y=x+1;y<=n;y++){
			   										for(int v=y+1;v<=n;v++){
														for(int f=v+1;f<=n;f++){
															for(int h=f+1;h<=n;h++){
																for(int d=h+1;d<=n;d++){
																	for(int g=d+1;g<=n;g++){
																		for(int r=g+1;r<=n;r++){
																			for(int w=r+1;w<=n;w++){
																				ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]&a[x]&a[y]&a[v]&a[f]&a[h]&a[d]&a[g]&a[r]&a[w]));
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	}else if(m==19){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											for(int x=z+1;x<=n;x++){
												for(int y=x+1;y<=n;y++){
			   										for(int v=y+1;v<=n;v++){
														for(int f=v+1;f<=n;f++){
															for(int h=f+1;h<=n;h++){
																for(int d=h+1;d<=n;d++){
																	for(int g=d+1;g<=n;g++){
																		for(int r=g+1;r<=n;r++){
																			for(int w=r+1;w<=n;w++){
																				for(int b=w+1;b<=n;b++){
																					ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]&a[x]&a[y]&a[v]&a[f]&a[h]&a[d]&a[g]&a[r]&a[w]&a[b]));
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	}else if(m==20){
		ma=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=o;p++){
								for(int q=p+1;q<=n;q++){
									for(int s=q+1;s<=n;s++){
										for(int z=s+1;z<=n;z++){
											for(int x=z+1;x<=n;x++){
												for(int y=x+1;y<=n;y++){
			   										for(int v=y+1;v<=n;v++){
														for(int f=v+1;f<=n;f++){
															for(int h=f+1;h<=n;h++){
																for(int d=h+1;d<=n;d++){
																	for(int g=d+1;g<=n;g++){
																		for(int r=g+1;r<=n;r++){
																			for(int w=r+1;w<=n;w++){
																				for(int b=w+1;b<=n;b++){
																					for(int u=b+1;u<=n;u++){
																						ma=max(ma,(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[s]&a[z]&a[x]&a[y]&a[v]&a[f]&a[h]&a[d]&a[g]&a[r]&a[w]&a[b]&a[u]));
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	}
	return 0;
}
