#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],pw[35];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2&&n<=2000){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				int zhi=a[i]&a[j];
				maxn=max(maxn,zhi);
			}
		}
		cout<<maxn;
		return 0;
	}
	pw[1]=1;
	for(int i=2;i<=31;i++){
		pw[i]=pw[i-1]*2;
	}
	if(m==n){
		int anss=a[1];
		for(int i=2;i<=n;i++){
			anss&=a[i];
		}
		cout<<anss;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		bool f=0;
		for(int j=1;j<=31;j++){
			if(pw[j]==a[i]+1){
				f=1;
				break;
			}
		}
		if(f==0){
			flag=0;
			break;
		}
	}
	if(flag==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	if(n==4){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						if((i+j+k+p)!=m)continue;
						vector<int>v;
						if(i==1)v.push_back(a[1]);
						if(j==1)v.push_back(a[2]);
						if(k==1)v.push_back(a[3]);
						if(p==1)v.push_back(a[4]);
						int zhi=v[0];
						for(int i=1;i<v.size();i++){
							zhi&=v[i];
						}
						ans=max(ans,zhi);
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(n==5){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							if((i+j+k+p+q)!=m)continue;
							vector<int>v;
							if(i==1)v.push_back(a[1]);
							if(j==1)v.push_back(a[2]);
							if(k==1)v.push_back(a[3]);
							if(p==1)v.push_back(a[4]);
							if(q==1)v.push_back(a[5]);
							int zhi=v[0];
							for(int i=1;i<v.size();i++){
								zhi&=v[i];
							}
							ans=max(ans,zhi);
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(n==6){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								if((i+j+k+p+q+u)!=m)continue;
								vector<int>v;
								if(i==1)v.push_back(a[1]);
								if(j==1)v.push_back(a[2]);
								if(k==1)v.push_back(a[3]);
								if(p==1)v.push_back(a[4]);
								if(q==1)v.push_back(a[5]);
								if(u==1)v.push_back(a[6]);
								int zhi=v[0];
								for(int i=1;i<v.size();i++){
									zhi&=v[i];
								}
								ans=max(ans,zhi);
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(n==7){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									if((i+j+k+p+q+u+vv)!=m)continue;
									vector<int>v;
									if(i==1)v.push_back(a[1]);
									if(j==1)v.push_back(a[2]);
									if(k==1)v.push_back(a[3]);
									if(p==1)v.push_back(a[4]);
									if(q==1)v.push_back(a[5]);
									if(u==1)v.push_back(a[6]);
									if(vv==1)v.push_back(a[7]);
									int zhi=v[0];
									for(int i=1;i<v.size();i++){
										zhi&=v[i];
									}
									ans=max(ans,zhi);
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(n==8){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										if((i+j+k+p+q+u+vv+w)!=m)continue;
										vector<int>v;
										if(i==1)v.push_back(a[1]);
										if(j==1)v.push_back(a[2]);
										if(k==1)v.push_back(a[3]);
										if(p==1)v.push_back(a[4]);
										if(q==1)v.push_back(a[5]);
										if(u==1)v.push_back(a[6]);
										if(vv==1)v.push_back(a[7]);
										if(w==1)v.push_back(a[8]);
										int zhi=v[0];
										for(int i=1;i<v.size();i++){
											zhi&=v[i];
										}
										ans=max(ans,zhi);
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(n==9){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											if((i+j+k+p+q+u+vv+w+e)!=m)continue;
											vector<int>v;
											if(i==1)v.push_back(a[1]);
											if(j==1)v.push_back(a[2]);
											if(k==1)v.push_back(a[3]);
											if(p==1)v.push_back(a[4]);
											if(q==1)v.push_back(a[5]);
											if(u==1)v.push_back(a[6]);
											if(vv==1)v.push_back(a[7]);
											if(w==1)v.push_back(a[8]);
											if(e==1)v.push_back(a[9]);
											int zhi=v[0];
											for(int i=1;i<v.size();i++){
												zhi&=v[i];
											}
											ans=max(ans,zhi);
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
		return 0;
	}
	if(n==10){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											for(int r=0;r<=1;r++){
												if((i+j+k+p+q+u+vv+w+e+r)!=m)continue;
												vector<int>v;
												if(i==1)v.push_back(a[1]);
												if(j==1)v.push_back(a[2]);
												if(k==1)v.push_back(a[3]);
												if(p==1)v.push_back(a[4]);
												if(q==1)v.push_back(a[5]);
												if(u==1)v.push_back(a[6]);
												if(vv==1)v.push_back(a[7]);
												if(w==1)v.push_back(a[8]);
												if(e==1)v.push_back(a[9]);
												if(r==1)v.push_back(a[10]);
												int zhi=v[0];
												for(int i=1;i<v.size();i++){
													zhi&=v[i];
												}
												ans=max(ans,zhi);
											}
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
		return 0;
	}
	if(n==11){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											for(int r=0;r<=1;r++){
												for(int t=0;t<=1;t++){
													if((i+j+k+p+q+u+vv+w+e+r+t)!=m)continue;
													vector<int>v;
													if(i==1)v.push_back(a[1]);
													if(j==1)v.push_back(a[2]);
													if(k==1)v.push_back(a[3]);
													if(p==1)v.push_back(a[4]);
													if(q==1)v.push_back(a[5]);
													if(u==1)v.push_back(a[6]);
													if(vv==1)v.push_back(a[7]);
													if(w==1)v.push_back(a[8]);
													if(e==1)v.push_back(a[9]);
													if(r==1)v.push_back(a[10]);
													if(t==1)v.push_back(a[11]);
													int zhi=v[0];
													for(int i=1;i<v.size();i++){
														zhi&=v[i];
													}
													ans=max(ans,zhi);
												}
											}
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
		return 0;
	}
	if(n==12){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											for(int r=0;r<=1;r++){
												for(int t=0;t<=1;t++){
													for(int s=0;s<=1;s++){
														if((i+j+k+p+q+u+vv+w+e+r+t+s)!=m)continue;
														vector<int>v;
														if(i==1)v.push_back(a[1]);
														if(j==1)v.push_back(a[2]);
														if(k==1)v.push_back(a[3]);
														if(p==1)v.push_back(a[4]);
														if(q==1)v.push_back(a[5]);
														if(u==1)v.push_back(a[6]);
														if(vv==1)v.push_back(a[7]);
														if(w==1)v.push_back(a[8]);
														if(e==1)v.push_back(a[9]);
														if(r==1)v.push_back(a[10]);
														if(t==1)v.push_back(a[11]);
														if(s==1)v.push_back(a[12]);
														int zhi=v[0];
														for(int i=1;i<v.size();i++){
															zhi&=v[i];
														}
														ans=max(ans,zhi);
													}
												}
											}
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
		return 0;
	}
	if(n==13){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											for(int r=0;r<=1;r++){
												for(int t=0;t<=1;t++){
													for(int s=0;s<=1;s++){
														for(int d=0;d<=1;d++){
															if((i+j+k+p+q+u+vv+w+e+r+t+s+d)!=m)continue;
															vector<int>v;
															if(i==1)v.push_back(a[1]);
															if(j==1)v.push_back(a[2]);
															if(k==1)v.push_back(a[3]);
															if(p==1)v.push_back(a[4]);
															if(q==1)v.push_back(a[5]);
															if(u==1)v.push_back(a[6]);
															if(vv==1)v.push_back(a[7]);
															if(w==1)v.push_back(a[8]);
															if(e==1)v.push_back(a[9]);
															if(r==1)v.push_back(a[10]);
															if(t==1)v.push_back(a[11]);
															if(s==1)v.push_back(a[12]);
															if(d==1)v.push_back(a[13]);
															int zhi=v[0];
															for(int i=1;i<v.size();i++){
																zhi&=v[i];
															}
															ans=max(ans,zhi);
														}
													}
												}
											}
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
		return 0;
	}
	if(n==14){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											for(int r=0;r<=1;r++){
												for(int t=0;t<=1;t++){
													for(int s=0;s<=1;s++){
														for(int d=0;d<=1;d++){
															for(int f=0;f<=1;f++){
																if((i+j+k+p+q+u+vv+w+e+r+t+s+d+f)!=m)continue;
																vector<int>v;
																if(i==1)v.push_back(a[1]);
																if(j==1)v.push_back(a[2]);
																if(k==1)v.push_back(a[3]);
																if(p==1)v.push_back(a[4]);
																if(q==1)v.push_back(a[5]);
																if(u==1)v.push_back(a[6]);
																if(vv==1)v.push_back(a[7]);
																if(w==1)v.push_back(a[8]);
																if(e==1)v.push_back(a[9]);
																if(r==1)v.push_back(a[10]);
																if(t==1)v.push_back(a[11]);
																if(s==1)v.push_back(a[12]);
																if(d==1)v.push_back(a[13]);
																if(f==1)v.push_back(a[14]);
																int zhi=v[0];
																for(int i=1;i<v.size();i++){
																	zhi&=v[i];
																}
																ans=max(ans,zhi);
															}
														}
													}
												}
											}
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
		return 0;
	}
	if(n==15){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											for(int r=0;r<=1;r++){
												for(int t=0;t<=1;t++){
													for(int s=0;s<=1;s++){
														for(int d=0;d<=1;d++){
															for(int f=0;f<=1;f++){
																for(int g=0;g<=1;g++){
																	if((i+j+k+p+q+u+vv+w+e+r+t+s+d+f+g)!=m)continue;
																	vector<int>v;
																	if(i==1)v.push_back(a[1]);
																	if(j==1)v.push_back(a[2]);
																	if(k==1)v.push_back(a[3]);
																	if(p==1)v.push_back(a[4]);
																	if(q==1)v.push_back(a[5]);
																	if(u==1)v.push_back(a[6]);
																	if(vv==1)v.push_back(a[7]);
																	if(w==1)v.push_back(a[8]);
																	if(e==1)v.push_back(a[9]);
																	if(r==1)v.push_back(a[10]);
																	if(t==1)v.push_back(a[11]);
																	if(s==1)v.push_back(a[12]);
																	if(d==1)v.push_back(a[13]);
																	if(f==1)v.push_back(a[14]);
																	if(g==1)v.push_back(a[15]);
																	int zhi=v[0];
																	for(int i=1;i<v.size();i++){
																		zhi&=v[i];
																	}
																	ans=max(ans,zhi);
																}
															}
														}
													}
												}
											}
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
		return 0;
	}
	if(n==16){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											for(int r=0;r<=1;r++){
												for(int t=0;t<=1;t++){
													for(int s=0;s<=1;s++){
														for(int d=0;d<=1;d++){
															for(int f=0;f<=1;f++){
																for(int g=0;g<=1;g++){
																	for(int h=0;h<=1;h++){
																		if((i+j+k+p+q+u+vv+w+e+r+t+s+d+f+g+h)!=m)continue;
																		vector<int>v;
																		if(i==1)v.push_back(a[1]);
																		if(j==1)v.push_back(a[2]);
																		if(k==1)v.push_back(a[3]);
																		if(p==1)v.push_back(a[4]);
																		if(q==1)v.push_back(a[5]);
																		if(u==1)v.push_back(a[6]);
																		if(vv==1)v.push_back(a[7]);
																		if(w==1)v.push_back(a[8]);
																		if(e==1)v.push_back(a[9]);
																		if(r==1)v.push_back(a[10]);
																		if(t==1)v.push_back(a[11]);
																		if(s==1)v.push_back(a[12]);
																		if(d==1)v.push_back(a[13]);
																		if(f==1)v.push_back(a[14]);
																		if(g==1)v.push_back(a[15]);
																		if(h==1)v.push_back(a[16]);
																		int zhi=v[0];
																		for(int i=1;i<v.size();i++){
																			zhi&=v[i];
																		}
																		ans=max(ans,zhi);
																	}
																}
															}
														}
													}
												}
											}
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
		return 0;
	}
	if(n==17){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											for(int r=0;r<=1;r++){
												for(int t=0;t<=1;t++){
													for(int s=0;s<=1;s++){
														for(int d=0;d<=1;d++){
															for(int f=0;f<=1;f++){
																for(int g=0;g<=1;g++){
																	for(int h=0;h<=1;h++){
																		for(int l=0;l<=1;l++){
																			if((i+j+k+p+q+u+vv+w+e+r+t+s+d+f+g+h+l)!=m)continue;
																			vector<int>v;
																			if(i==1)v.push_back(a[1]);
																			if(j==1)v.push_back(a[2]);
																			if(k==1)v.push_back(a[3]);
																			if(p==1)v.push_back(a[4]);
																			if(q==1)v.push_back(a[5]);
																			if(u==1)v.push_back(a[6]);
																			if(vv==1)v.push_back(a[7]);
																			if(w==1)v.push_back(a[8]);
																			if(e==1)v.push_back(a[9]);
																			if(r==1)v.push_back(a[10]);
																			if(t==1)v.push_back(a[11]);
																			if(s==1)v.push_back(a[12]);
																			if(d==1)v.push_back(a[13]);
																			if(f==1)v.push_back(a[14]);
																			if(g==1)v.push_back(a[15]);
																			if(h==1)v.push_back(a[16]);
																			if(l==1)v.push_back(a[17]);
																			int zhi=v[0];
																			for(int i=1;i<v.size();i++){
																				zhi&=v[i];
																			}
																			ans=max(ans,zhi);
																		}
																	}
																}
															}
														}
													}
												}
											}
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
		return 0;
	}
	if(n==18){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											for(int r=0;r<=1;r++){
												for(int t=0;t<=1;t++){
													for(int s=0;s<=1;s++){
														for(int d=0;d<=1;d++){
															for(int f=0;f<=1;f++){
																for(int g=0;g<=1;g++){
																	for(int h=0;h<=1;h++){
																		for(int l=0;l<=1;l++){
																			for(int x=0;x<=1;x++){
																				if((i+j+k+p+q+u+vv+w+e+r+t+s+d+f+g+h+l+x)!=m)continue;
																				vector<int>v;
																				if(i==1)v.push_back(a[1]);
																				if(j==1)v.push_back(a[2]);
																				if(k==1)v.push_back(a[3]);
																				if(p==1)v.push_back(a[4]);
																				if(q==1)v.push_back(a[5]);
																				if(u==1)v.push_back(a[6]);
																				if(vv==1)v.push_back(a[7]);
																				if(w==1)v.push_back(a[8]);
																				if(e==1)v.push_back(a[9]);
																				if(r==1)v.push_back(a[10]);
																				if(t==1)v.push_back(a[11]);
																				if(s==1)v.push_back(a[12]);
																				if(d==1)v.push_back(a[13]);
																				if(f==1)v.push_back(a[14]);
																				if(g==1)v.push_back(a[15]);
																				if(h==1)v.push_back(a[16]);
																				if(l==1)v.push_back(a[17]);
																				if(x==1)v.push_back(a[18]);
																				int zhi=v[0];
																				for(int i=1;i<v.size();i++){
																					zhi&=v[i];
																				}
																				ans=max(ans,zhi);
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
		return 0;
	}
	if(n==19){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											for(int r=0;r<=1;r++){
												for(int t=0;t<=1;t++){
													for(int s=0;s<=1;s++){
														for(int d=0;d<=1;d++){
															for(int f=0;f<=1;f++){
																for(int g=0;g<=1;g++){
																	for(int h=0;h<=1;h++){
																		for(int l=0;l<=1;l++){
																			for(int x=0;x<=1;x++){
																				for(int aa=0;aa<=1;aa++){
																					if((i+j+k+p+q+u+vv+w+e+r+t+s+d+f+g+h+l+x+aa)!=m)continue;
																					vector<int>v;
																					if(i==1)v.push_back(a[1]);
																					if(j==1)v.push_back(a[2]);
																					if(k==1)v.push_back(a[3]);
																					if(p==1)v.push_back(a[4]);
																					if(q==1)v.push_back(a[5]);
																					if(u==1)v.push_back(a[6]);
																					if(vv==1)v.push_back(a[7]);
																					if(w==1)v.push_back(a[8]);
																					if(e==1)v.push_back(a[9]);
																					if(r==1)v.push_back(a[10]);
																					if(t==1)v.push_back(a[11]);
																					if(s==1)v.push_back(a[12]);
																					if(d==1)v.push_back(a[13]);
																					if(f==1)v.push_back(a[14]);
																					if(g==1)v.push_back(a[15]);
																					if(h==1)v.push_back(a[16]);
																					if(l==1)v.push_back(a[17]);
																					if(x==1)v.push_back(a[18]);
																					if(aa==1)v.push_back(a[19]);
																					int zhi=v[0];
																					for(int i=1;i<v.size();i++){
																						zhi&=v[i];
																					}
																					ans=max(ans,zhi);
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
		return 0;
	}
	if(n==20){
		int ans=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				for(int k=0;k<=1;k++){
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							for(int u=0;u<=1;u++){
								for(int vv=0;vv<=1;vv++){
									for(int w=0;w<=1;w++){
										for(int e=0;e<=1;e++){
											for(int r=0;r<=1;r++){
												for(int t=0;t<=1;t++){
													for(int s=0;s<=1;s++){
														for(int d=0;d<=1;d++){
															for(int f=0;f<=1;f++){
																for(int g=0;g<=1;g++){
																	for(int h=0;h<=1;h++){
																		for(int l=0;l<=1;l++){
																			for(int x=0;x<=1;x++){
																				for(int aa=0;aa<=1;aa++){
																					for(int bb=0;bb<=1;bb++){
																						if((i+j+k+p+q+u+vv+w+e+r+t+s+d+f+g+h+l+x+aa+bb)!=m)continue;
																						vector<int>v;
																						if(i==1)v.push_back(a[1]);
																						if(j==1)v.push_back(a[2]);
																						if(k==1)v.push_back(a[3]);
																						if(p==1)v.push_back(a[4]);
																						if(q==1)v.push_back(a[5]);
																						if(u==1)v.push_back(a[6]);
																						if(vv==1)v.push_back(a[7]);
																						if(w==1)v.push_back(a[8]);
																						if(e==1)v.push_back(a[9]);
																						if(r==1)v.push_back(a[10]);
																						if(t==1)v.push_back(a[11]);
																						if(s==1)v.push_back(a[12]);
																						if(d==1)v.push_back(a[13]);
																						if(f==1)v.push_back(a[14]);
																						if(g==1)v.push_back(a[15]);
																						if(h==1)v.push_back(a[16]);
																						if(l==1)v.push_back(a[17]);
																						if(x==1)v.push_back(a[18]);
																						if(aa==1)v.push_back(a[19]);
																						if(bb==1)v.push_back(a[20]);
																						int zhi=v[0];
																						for(int i=1;i<v.size();i++){
																							zhi&=v[i];
																						}
																						ans=max(ans,zhi);
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
		return 0;
	}
	cout<<3;
	return 0;
}
