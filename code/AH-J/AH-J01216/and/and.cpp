#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],maxt=0,mx=0,t,nt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	nt=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		maxt=max(maxt,a[i]);
		nt=nt&a[i];
	}
	if(m==1){
		cout<<maxt;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				t=a[i]&a[j];
				mx=max(mx,t);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<nt;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					t=a[i]&a[j]&a[k];
					mx=max(mx,t);
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						t=a[i]&a[j]&a[k]&a[l];
						mx=max(mx,t);
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							t=a[i]&a[j]&a[k]&a[l]&a[o];
							mx=max(mx,t);
						}
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
								mx=max(mx,t);
							}
						}
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q];
									mx=max(mx,t);
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
	if(m==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r];
										mx=max(mx,t);
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
	if(m==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u];
											mx=max(mx,t);
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
	if(m==10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u]&a[v];
												mx=max(mx,t);
											}
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
	if(m==11){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w];
													mx=max(mx,t);
												}
											}
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
	if(m==12){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													for(int x=w+1;x<=n;x++){
														t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[x];
														mx=max(mx,t);
													}
												}
											}
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
	if(m==13){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													for(int x=w+1;x<=n;x++){
														for(int y=x+1;y<=n;y++){
															t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[x]&a[y];
															mx=max(mx,t);
														}
													}
												}
											}
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
	if(m==14){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													for(int x=w+1;x<=n;x++){
														for(int y=x+1;y<=n;y++){
															for(int z=y+1;z<=n;z++){
																t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z];
																mx=max(mx,t);
															}
														}
													}
												}
											}
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
	if(m==15){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													for(int x=w+1;x<=n;x++){
														for(int y=x+1;y<=n;y++){
															for(int z=y+1;z<=n;z++){
																for(int b=z+1;b<=n;b++){
																	t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]&a[b];
																	mx=max(mx,t);
																}
															}
														}
													}
												}
											}
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
	if(m==16){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													for(int x=w+1;x<=n;x++){
														for(int y=x+1;y<=n;y++){
															for(int z=y+1;z<=n;z++){
																for(int b=z+1;b<=n;b++){
																	for(int c=b+1;c<=n;c++){
																		t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]&a[b]&a[c];
																		mx=max(mx,t);
																	}
																}
															}
														}
													}
												}
											}
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
	if(m==17){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													for(int x=w+1;x<=n;x++){
														for(int y=x+1;y<=n;y++){
															for(int z=y+1;z<=n;z++){
																for(int b=z+1;b<=n;b++){
																	for(int c=b+1;c<=n;c++){
																		for(int d=c+1;d<=n;d++){
																			t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]&a[b]&a[c]&a[d];
																			mx=max(mx,t);
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	if(m==18){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													for(int x=w+1;x<=n;x++){
														for(int y=x+1;y<=n;y++){
															for(int z=y+1;z<=n;z++){
																for(int b=z+1;b<=n;b++){
																	for(int c=b+1;c<=n;c++){
																		for(int d=c+1;d<=n;d++){
																			for(int e=d+1;e<=n;e++){
																				t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]&a[b]&a[c]&a[d]&a[e];
																				mx=max(mx,t);
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	if(m==19){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													for(int x=w+1;x<=n;x++){
														for(int y=x+1;y<=n;y++){
															for(int z=y+1;z<=n;z++){
																for(int b=z+1;b<=n;b++){
																	for(int c=b+1;c<=n;c++){
																		for(int d=c+1;d<=n;d++){
																			for(int e=d+1;e<=n;e++){
																				for(int f=e+1;f<=n;f++){
																					t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]&a[b]&a[c]&a[d]&a[e]&a[f];
																					mx=max(mx,t);
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	if(m==20){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int u=r+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													for(int x=w+1;x<=n;x++){
														for(int y=x+1;y<=n;y++){
															for(int z=y+1;z<=n;z++){
																for(int b=z+1;b<=n;b++){
																	for(int c=b+1;c<=n;c++){
																		for(int d=c+1;d<=n;d++){
																			for(int e=d+1;e<=n;e++){
																				for(int f=e+1;f<=n;f++){
																					for(int g=f+1;g<=n;g++){
																						t=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[u]&a[v]&a[w]&a[x]&a[y]&a[z]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g];
																						mx=max(mx,t);
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	return 0;
}
