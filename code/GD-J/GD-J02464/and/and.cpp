#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200010];
long long tot;
long long ma;
long long ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) tot=a[i];
		else tot=tot&a[i];
		ma=max(ma,a[i]);
	}
	if(n==m) cout<<tot;
	else if(m==1) cout<<ma;
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<ans;
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						ans=max(ans,a[i]&a[j]&a[k]&a[l]);
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]);
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]);
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]);
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]);
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int e=q+1;e<=n;e++){
											ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]&a[e]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int e=q+1;e<=n;e++){
											for(int t=e+1;t<=n;t++){
												ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]&a[e]&a[t]);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==11){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int e=q+1;e<=n;e++){
											for(int t=e+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]&a[e]&a[t]&a[y]);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==12){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int e=q+1;e<=n;e++){
											for(int t=e+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]&a[e]&a[t]&a[y]&a[u]);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==13){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int e=q+1;e<=n;e++){
											for(int t=e+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]&a[e]&a[t]&a[y]&a[u]&a[o]);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==14){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int e=q+1;e<=n;e++){
											for(int t=e+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int p=o+1;p<=n;p++){
																ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]&a[e]&a[t]&a[y]&a[u]&a[o]&a[p]);
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==15){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int e=q+1;e<=n;e++){
											for(int t=e+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int p=o+1;p<=n;p++){
																for(int s=p+1;s<=n;s++){
																	ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]&a[e]&a[t]&a[y]&a[u]&a[o]&a[p]&a[s]);
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==16){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int e=q+1;e<=n;e++){
											for(int t=e+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int p=o+1;p<=n;p++){
																for(int s=p+1;s<=n;s++){
																	for(int d=s+1;d<=n;d++){
																		ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]&a[e]&a[t]&a[y]&a[u]&a[o]&a[p]&a[s]);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==17){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int e=q+1;e<=n;e++){
											for(int t=e+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int p=o+1;p<=n;p++){
																for(int s=p+1;s<=n;s++){
																	for(int d=s+1;d<=n;d++){
																		for(int g=d+1;g<=n;g++){
																			ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]&a[e]&a[t]&a[y]&a[u]&a[o]&a[p]&a[s]&a[g]);
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==18){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int e=q+1;e<=n;e++){
											for(int t=e+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int p=o+1;p<=n;p++){
																for(int s=p+1;s<=n;s++){
																	for(int d=s+1;d<=n;d++){
																		for(int g=d+1;g<=n;g++){
																			for(int h=g+1;h<=n;h++){
																				ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]&a[e]&a[t]&a[y]&a[u]&a[o]&a[p]&a[s]&a[g]);
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(m==19){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int f=r+1;f<=n;f++){
								for(int w=f+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int e=q+1;e<=n;e++){
											for(int t=e+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int p=o+1;p<=n;p++){
																for(int s=p+1;s<=n;s++){
																	for(int d=s+1;d<=n;d++){
																		for(int g=d+1;g<=n;g++){
																			for(int h=g+1;h<=n;h++){
																				for(int z=h+1;z<=n;z++){
																					ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[f]&a[w]&a[q]&a[e]&a[t]&a[y]&a[u]&a[o]&a[p]&a[s]&a[g]&a[z]);
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else cout<<(n+1)/2; 
	return 0;
} 
