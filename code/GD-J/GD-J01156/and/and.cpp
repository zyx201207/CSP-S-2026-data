#include<bits/stdc++.h>
using namespace std;
int a[300010];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if(m == n){
		cin >> a[1];
		int ans = a[1];
		for(int i = 2;i <= n; i++){
			cin >> a[i];
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if(m == n-1){
		int ans = a[2];
		for(int i = 1;i <= n; i++){
			cin >> a[i];
		}
		for(int i = 3; i <= n; i++){
			ans &= a[i];
		}
		int i = 2;
		while(i <= n){
			int cnt = a[1];
			for(int j = 1; j <= n; j++){
				if(j != i && j != 1){
					cnt &= a[j];
				}
			}
			ans = max(ans , cnt);
			i++;
		}
		cout << ans;
		return 0;
	}
	if(m == 1){
		int ans = INT_MIN;
		for(int i = 1;i <= n; i++){
			cin >> a[i];
			ans = max(a[i], ans);
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				ans = max(ans, a[i]&a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 3){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				for(int k = j+1; k <= n; k++){
					ans = max(ans,a[i]&a[j]&a[k]);
				}
			} 
		}
		cout << ans;
		return 0;
	}
	if(m == 4){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						ans = max(ans,a[i]&a[j]&a[k]&a[u]);
					}
			    }
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 5){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]);
						}
					}
			    }
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 6){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]);
					    	}
						}
					}
			    }
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 7){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]);
					    		}
					    	}
						}
					}
			    }
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 8){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]);
					    			}
					    		}
					    	}
						}
					}
			    }
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 9){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										for(int w = e+1; w <= n; w++){
											ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]&a[w]);
					    				}
					    			}
					    		}
							}
						}
			    	}
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 10){
	    int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										for(int w = e+1; w <= n; w++){
											for(int q = w+1; q <= n; q++){
												ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]&a[w]&a[q]);
					    					}
					    				}
					    			}
					    		}
							}
						}
			    	}
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 11){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										for(int w = e+1; w <= n; w++){
											for(int q = w+1; q <= n; q++){
												for(int s = q+1; s <= n; s++){
													ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]&a[w]&a[q]&a[s]);
					    						}
					    					}
					    				}
					    			}
					    		}
							}
						}
			    	}
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 12){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										for(int w = e+1; w <= n; w++){
											for(int q = w+1; q <= n; q++){
												for(int s = q+1; s <= n; s++){
													for(int d = s+1; d <= n; d++){
														ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]&a[w]&a[q]&a[s]&a[d]);
					    							}
					    						}
					    					}
					    				}
					    			}
					    		}
							}
						}
			    	}
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 13){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										for(int w = e+1; w <= n; w++){
											for(int q = w+1; q <= n; q++){
												for(int s = q+1; s <= n; s++){
													for(int d = s+1; d <= n; d++){
														for(int f = d+1; f <= n;f ++){
															ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]&a[w]&a[q]&a[s]&a[d]&a[f]);
					    								}
					    							}
					    						}
					    					}
					    				}
					    			}
					    		}
							}
						}
			    	}
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 14){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										for(int w = e+1; w <= n; w++){
											for(int q = w+1; q <= n; q++){
												for(int s = q+1; s <= n; s++){
													for(int d = s+1; d <= n; d++){
														for(int f = d+1; f <= n;f ++){
															for(int g= f+1; g<= n; g++){
																ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]&a[w]&a[q]&a[s]&a[d]&a[f]&a[g]);
					    									}
					    								}
					    							}
					    						}
					    					}
					    				}
					    			}
					    		}
							}
						}
			    	}
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 15){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										for(int w = e+1; w <= n; w++){
											for(int q = w+1; q <= n; q++){
												for(int s = q+1; s <= n; s++){
													for(int d = s+1; d <= n; d++){
														for(int f = d+1; f <= n;f ++){
															for(int g= f+1; g<= n; g++){
																for(int h = g+1; h <= n; h++){
																	ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]&a[w]&a[q]&a[s]&a[d]&a[f]&a[g]&a[h]);
					    										}
					    									}
					    								}
					    							}
					    						}
					    					}
					    				}
					    			}
					    		}
							}
						}
			    	}
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 16){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										for(int w = e+1; w <= n; w++){
											for(int q = w+1; q <= n; q++){
												for(int s = q+1; s <= n; s++){
													for(int d = s+1; d <= n; d++){
														for(int f = d+1; f <= n;f ++){
															for(int g= f+1; g<= n; g++){
																for(int h = g+1; h <= n; h++){
																	for(int l = h + 1; l <= n; l++){
																		ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]&a[w]&a[q]&a[s]&a[d]&a[f]&a[g]&a[h]&a[l]);
					    											}
					    										}
					    									}
					    								}
					    							}
					    						}
					    					}
					    				}
					    			}
					    		}
							}
						}
			    	}
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 17){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										for(int w = e+1; w <= n; w++){
											for(int q = w+1; q <= n; q++){
												for(int s = q+1; s <= n; s++){
													for(int d = s+1; d <= n; d++){
														for(int f = d+1; f <= n;f ++){
															for(int g= f+1; g<= n; g++){
																for(int h = g+1; h <= n; h++){
																	for(int l = h + 1; l <= n; l++){
																		for(int z = l+1; z <= n; z++){
																			ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]&a[w]&a[q]&a[s]&a[d]&a[f]&a[g]&a[h]&a[l]&a[z]);
					    												}
					    											}
					    										}
					    									}
					    								}
					    							}
					    						}
					    					}
					    				}
					    			}
					    		}
							}
						}
			    	}
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 18){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										for(int w = e+1; w <= n; w++){
											for(int q = w+1; q <= n; q++){
												for(int s = q+1; s <= n; s++){
													for(int d = s+1; d <= n; d++){
														for(int f = d+1; f <= n;f ++){
															for(int g= f+1; g<= n; g++){
																for(int h = g+1; h <= n; h++){
																	for(int l = h + 1; l <= n; l++){
																		for(int z = l+1; z <= n; z++){
																			for(int x = z+1; x <= n; x++){
																				ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]&a[w]&a[q]&a[s]&a[d]&a[f]&a[g]&a[h]&a[l]&a[z]&a[x]);
					    													}
					    												}
					    											}
					    										}
					    									}
					    								}
					    							}
					    						}
					    					}
					    				}
					    			}
					    		}
							}
						}
			    	}
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(m == 19){
		int ans = INT_MIN;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			for(int j = i+1;j <= n; j++){
				for(int k = j+1; k <= n; k++){
					for(int u = k+1; u <= n; u++){
						for(int y = u+1; y <= n; y++){
							for(int t = y+1; t <= n; t++){
								for(int r = t +1; r <= n; r++){
									for(int e = r+1; e <= n; e++){
										for(int w = e+1; w <= n; w++){
											for(int q = w+1; q <= n; q++){
												for(int s = q+1; s <= n; s++){
													for(int d = s+1; d <= n; d++){
														for(int f = d+1; f <= n;f ++){
															for(int g= f+1; g<= n; g++){
																for(int h = g+1; h <= n; h++){
																	for(int l = h + 1; l <= n; l++){
																		for(int z = l+1; z <= n; z++){
																			for(int x = z+1; x <= n; x++){
																				for(int c = x+1; c <= n; c++){
																					ans = max(ans, a[i]&a[j]&a[k]&a[u]&a[y]&a[t]&a[r]&a[e]&a[w]&a[q]&a[s]&a[d]&a[f]&a[g]&a[h]&a[l]&a[z]&a[x]&a[c]);
					    														}
					    													}
					    												}
					    											}
					    										}
					    									}
					    								}
					    							}
					    						}
					    					}
					    				}
					    			}
					    		}
							}
						}
			    	}
				}
			}
		}
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
