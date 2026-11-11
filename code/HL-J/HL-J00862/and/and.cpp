#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],max1=-1e18;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(m==2){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    max1=max(a[i]&a[j],max1);
			}
		}cout<<max1;
		return 0;
	}if(m==n){
		int x=0;
		for(int i=1;i<=n;i++){
			x=x&a[i];
		}cout<<x;
		return 0;
	}if(m==1){
		for(int i=1;i<=n;i++){
			max1=max(max1,a[i]);
		}cout<<max1;
		return 0;
	}if(n<=20){
		if(m==3){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		max1=max(a[i]&a[j]&a[k],max1);
				    }  
			    }
		    }
		}cout<<max1;
		if(m==4){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		max1=max(a[i]&a[j]&a[k]&a[b],max1);
				    }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==5){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		        max1=max(a[i]&a[j]&a[k]&a[b]&a[c],max1);
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==6){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		            max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d],max1);
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==7){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e],max1);
									}
								}
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==8){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f],max1);
										}
									}
								
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==9){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    for(int g=f+1;g<=n;g++){
		        		    			    	max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g],max1);
											}
										}
									}
								
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==10){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    for(int g=f+1;g<=n;g++){
		        		    			    	for(int h=g+1;h<=n;h++){
		        		    			    		max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h],max1);
												}
											}
										}
									}
								
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==11){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    for(int g=f+1;g<=n;g++){
		        		    			    	for(int h=g+1;h<=n;h++){
		        		    			    		for(int l=h+1;l<=n;l++){
		        		    			    			max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l],max1);
													}
												}
											}
										}
									}
								
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==12){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    for(int g=f+1;g<=n;g++){
		        		    			    	for(int h=g+1;h<=n;h++){
		        		    			    		for(int l=h+1;l<=n;l++){
		        		    			    			for(int o=l+1;o<=n;o++){
		        		    			    				max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o],max1);
														}
		        		    			    			
													}
												}
											}
										}
									}
								
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==13){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    for(int g=f+1;g<=n;g++){
		        		    			    	for(int h=g+1;h<=n;h++){
		        		    			    		for(int l=h+1;l<=n;l++){
		        		    			    			for(int o=l+1;o<=n;o++){
		        		    			    				for(int p=o+1;p<=n;p++){
		        		    			    					max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p],max1);
															}
														}
													}
												}
											}
										}
									}
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==14){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    for(int g=f+1;g<=n;g++){
		        		    			    	for(int h=g+1;h<=n;h++){
		        		    			    		for(int l=h+1;l<=n;l++){
		        		    			    			for(int o=l+1;o<=n;o++){
		        		    			    				for(int p=o+1;p<=n;p++){
		        		    			    					for(int q=p+1;q<=n;q++){
		        		    			    				        max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q],max1);
																}
															}
														}
													}
												}
											}
										}
									}
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==15){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    for(int g=f+1;g<=n;g++){
		        		    			    	for(int h=g+1;h<=n;h++){
		        		    			    		for(int l=h+1;l<=n;l++){
		        		    			    			for(int o=l+1;o<=n;o++){
		        		    			    				for(int p=o+1;p<=n;p++){
		        		    			    					for(int q=p+1;q<=n;q++){
		        		    			    						for(int r=q+1;r<=n;r++){
		        		    			    							max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q]&a[r],max1);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==16){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    for(int g=f+1;g<=n;g++){
		        		    			    	for(int h=g+1;h<=n;h++){
		        		    			    		for(int l=h+1;l<=n;l++){
		        		    			    			for(int o=l+1;o<=n;o++){
		        		    			    				for(int p=o+1;p<=n;p++){
		        		    			    					for(int q=p+1;q<=n;q++){
		        		    			    						for(int r=q+1;r<=n;r++){
		        		    			    							for(int s=r+1;s<=n;s++){
		        		    			    								max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s],max1);
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==17){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    for(int g=f+1;g<=n;g++){
		        		    			    	for(int h=g+1;h<=n;h++){
		        		    			    		for(int l=h+1;l<=n;l++){
		        		    			    			for(int o=l+1;o<=n;o++){
		        		    			    				for(int p=o+1;p<=n;p++){
		        		    			    					for(int q=p+1;q<=n;q++){
		        		    			    						for(int r=q+1;r<=n;r++){
		        		    			    							for(int s=r+1;s<=n;s++){
		        		    			    								for(int t=s+1;t<=n;t++){
		        		    			    									max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t],max1);
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==18){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    for(int g=f+1;g<=n;g++){
		        		    			    	for(int h=g+1;h<=n;h++){
		        		    			    		for(int l=h+1;l<=n;l++){
		        		    			    			for(int o=l+1;o<=n;o++){
		        		    			    				for(int p=o+1;p<=n;p++){
		        		    			    					for(int q=p+1;q<=n;q++){
		        		    			    						for(int r=q+1;r<=n;r++){
		        		    			    							for(int s=r+1;s<=n;s++){
		        		    			    								for(int t=s+1;t<=n;t++){
		        		    			    									for(int u=t+1;u<=n;u++){
		        		    			    										max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u],max1);
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
		if(m==19){
			for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		        	for(int k=j+1;k<=n;k++){
		        		for(int b=k+1;b<=n;b++){
		        		    for(int c=b+1;c<=n;c++){
		        		    	for(int d=c+1;d<=n;d++){
		        		    		for(int e=d+1;e<=n;e++){
		        		    			for(int f=e+1;f<=n;f++){
		        		    			    for(int g=f+1;g<=n;g++){
		        		    			    	for(int h=g+1;h<=n;h++){
		        		    			    		for(int l=h+1;l<=n;l++){
		        		    			    			for(int o=l+1;o<=n;o++){
		        		    			    				for(int p=o+1;p<=n;p++){
		        		    			    					for(int q=p+1;q<=n;q++){
		        		    			    						for(int r=q+1;r<=n;r++){
		        		    			    							for(int s=r+1;s<=n;s++){
		        		    			    								for(int t=s+1;t<=n;t++){
		        		    			    									for(int u=t+1;u<=n;u++){
		        		    			    										for(int v=u+1;v<=n;v++){
		        		    			    											max1=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v],max1);
																					}
																				}
		        		    			    									
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
		        		        }
				            }
				        }
				    }  
			    }
		    }
		}cout<<max1;
	}
	return 0;
}