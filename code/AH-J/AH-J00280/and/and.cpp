#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					maxn=max(maxn,(a[i]&a[j]&a[k]));
				}
			}
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
	}else if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					for(int s=1;s<=n;s++){
						if(s==i||s==j||s==k)continue;
						maxn=max(maxn,(a[i]&a[j]&a[k]&a[s]));
					}
				}
			}
		}
	}else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					for(int s=1;s<=n;s++){
						if(s==i||s==j||s==k)continue;
						for(int t=1;t<=n;t++){
							if(t==i||t==j||t==k||t==s)continue;
							maxn=max(maxn,(a[i]&a[j]&a[k]&a[s]&a[t]));
						}
					}
				}
			}
		}
	}else if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					for(int s=1;s<=n;s++){
						if(s==i||s==j||s==k)continue;
						for(int t=1;t<=n;t++){
							if(t==i||t==j||t==k||t==s)continue;
							for(int z=1;z<=n;z++){
								if(z==i||z==j||z==k||z==s||z==t)continue;
								maxn=max(maxn,(a[i]&a[j]&a[k]&a[s]&a[t]&a[z]));
							}
						}
					}
				}
			}
		}
	}else if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					for(int s=1;s<=n;s++){
						if(s==i||s==j||s==k)continue;
						for(int t=1;t<=n;t++){
							if(t==i||t==j||t==k||t==s)continue;
							for(int z=1;z<=n;z++){
								if(z==i||z==j||z==k||z==s||z==t)continue;
								for(int f=1;f<=n;f++){
									if(f==i||f==j||f==k||f==s||f==t||f==z)continue;
									maxn=max(maxn,(a[i]&a[j]&a[k]&a[s]&a[t]&a[z]&a[f]));
								}
							}
						}
					}
				}
			}
		}
	}else if(m==8){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					for(int s=1;s<=n;s++){
						if(s==i||s==j||s==k)continue;
						for(int t=1;t<=n;t++){
							if(t==i||t==j||t==k||t==s)continue;
							for(int z=1;z<=n;z++){
								if(z==i||z==j||z==k||z==s||z==t)continue;
								for(int f=1;f<=n;f++){
									if(f==i||f==j||f==k||f==s||f==t||f==z)continue;
									for(int l=1;l<=n;l++){
										if(l==i||l==j||l==k||l==s||l==t||l==z||l==f)continue;
										maxn=max(maxn,(a[i]&a[j]&a[k]&a[s]&a[t]&a[z]&a[f]&a[l]));
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(m==9){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					for(int s=1;s<=n;s++){
						if(s==i||s==j||s==k)continue;
						for(int t=1;t<=n;t++){
							if(t==i||t==j||t==k||t==s)continue;
							for(int z=1;z<=n;z++){
								if(z==i||z==j||z==k||z==s||z==t)continue;
								for(int f=1;f<=n;f++){
									if(f==i||f==j||f==k||f==s||f==t||f==z)continue;
									for(int l=1;l<=n;l++){
										if(l==i||l==j||l==k||l==s||l==t||l==z||l==f)continue;
										for(int y=1;y<=n;y++){
											if(y==i||y==j||y==k||y==s||y==t||y==z||y==f||y==l)continue;
											maxn=max(maxn,(a[i]&a[j]&a[k]&a[s]&a[t]&a[z]&a[f]&a[l]&a[y]));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(m==10){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					for(int s=1;s<=n;s++){
						if(s==i||s==j||s==k)continue;
						for(int t=1;t<=n;t++){
							if(t==i||t==j||t==k||t==s)continue;
							for(int z=1;z<=n;z++){
								if(z==i||z==j||z==k||z==s||z==t)continue;
								for(int f=1;f<=n;f++){
									if(f==i||f==j||f==k||f==s||f==t||f==z)continue;
									for(int l=1;l<=n;l++){
										if(l==i||l==j||l==k||l==s||l==t||l==z||l==f)continue;
										for(int y=1;y<=n;y++){
											if(y==i||y==j||y==k||y==s||y==t||y==z||y==f||y==l)continue;
											for(int c=1;c<=n;c++){
												if(c==i||c==j||c==k||c==s||c==t||c==z||c==f||c==l||c==y)continue;
												maxn=max(maxn,(a[i]&a[j]&a[k]&a[s]&a[t]&a[z]&a[f]&a[l]&a[y]&a[c]));
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(m==11){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					for(int s=1;s<=n;s++){
						if(s==i||s==j||s==k)continue;
						for(int t=1;t<=n;t++){
							if(t==i||t==j||t==k||t==s)continue;
							for(int z=1;z<=n;z++){
								if(z==i||z==j||z==k||z==s||z==t)continue;
								for(int f=1;f<=n;f++){
									if(f==i||f==j||f==k||f==s||f==t||f==z)continue;
									for(int l=1;l<=n;l++){
										if(l==i||l==j||l==k||l==s||l==t||l==z||l==f)continue;
										for(int y=1;y<=n;y++){
											if(y==i||y==j||y==k||y==s||y==t||y==z||y==f||y==l)continue;
											for(int c=1;c<=n;c++){
												if(c==i||c==j||c==k||c==s||c==t||c==z||c==f||c==l||c==y)continue;
												for(int v=1;v<=n;v++){
													if(v==i||v==j||v==k||v==s||v==t||v==z||v==f||v==l||v==y||v==c)continue;
													maxn=max(maxn,(a[i]&a[j]&a[k]&a[s]&a[t]&a[z]&a[f]&a[l]&a[y]&a[c]&a[v]));
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(m==12){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					for(int s=1;s<=n;s++){
						if(s==i||s==j||s==k)continue;
						for(int t=1;t<=n;t++){
							if(t==i||t==j||t==k||t==s)continue;
							for(int z=1;z<=n;z++){
								if(z==i||z==j||z==k||z==s||z==t)continue;
								for(int f=1;f<=n;f++){
									if(f==i||f==j||f==k||f==s||f==t||f==z)continue;
									for(int l=1;l<=n;l++){
										if(l==i||l==j||l==k||l==s||l==t||l==z||l==f)continue;
										for(int y=1;y<=n;y++){
											if(y==i||y==j||y==k||y==s||y==t||y==z||y==f||y==l)continue;
											for(int c=1;c<=n;c++){
												if(c==i||c==j||c==k||c==s||c==t||c==z||c==f||c==l||c==y)continue;
												for(int v=1;v<=n;v++){
													if(v==i||v==j||v==k||v==s||v==t||v==z||v==f||v==l||v==y||v==c)continue;
													for(int b=1;b<=n;b++){
														if(b==i||b==j||b==k||b==s||b==t||b==z||b==f||b==l||b==y||b==c||b==v)continue;
														maxn=max(maxn,(a[i]&a[j]&a[k]&a[s]&a[t]&a[z]&a[f]&a[l]&a[y]&a[c]&a[v]&a[b]));
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(m==13){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					for(int s=1;s<=n;s++){
						if(s==i||s==j||s==k)continue;
						for(int t=1;t<=n;t++){
							if(t==i||t==j||t==k||t==s)continue;
							for(int z=1;z<=n;z++){
								if(z==i||z==j||z==k||z==s||z==t)continue;
								for(int f=1;f<=n;f++){
									if(f==i||f==j||f==k||f==s||f==t||f==z)continue;
									for(int l=1;l<=n;l++){
										if(l==i||l==j||l==k||l==s||l==t||l==z||l==f)continue;
										for(int y=1;y<=n;y++){
											if(y==i||y==j||y==k||y==s||y==t||y==z||y==f||y==l)continue;
											for(int c=1;c<=n;c++){
												if(c==i||c==j||c==k||c==s||c==t||c==z||c==f||c==l||c==y)continue;
												for(int v=1;v<=n;v++){
													if(v==i||v==j||v==k||v==s||v==t||v==z||v==f||v==l||v==y||v==c)continue;
													for(int b=1;b<=n;b++){
														if(b==i||b==j||b==k||b==s||b==t||b==z||b==f||b==l||b==y||b==c||b==v)continue;
														for(int u=1;u<=n;u++){
															if(u==i||u==j||u==k||u==s||u==t||u==z||u==f||u==l||u==y||u==c||u==v||u==b)continue;
															maxn=max(maxn,(a[i]&a[j]&a[k]&a[s]&a[t]&a[z]&a[f]&a[l]&a[y]&a[c]&a[v]&a[b]&a[u]));
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}
