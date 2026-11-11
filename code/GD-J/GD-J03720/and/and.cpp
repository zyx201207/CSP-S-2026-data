#include <bits/stdc++.h>
using ll = int;
using namespace std;
ll n,m;
ll a[100005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(m==n) {
		ll sum;
		cin>>sum;
		for(int i = 2 ;i<=n;i++){
			ll x;
			cin>>x;
			sum=sum&x;
		}
		cout<<sum;
	}else if(m==1){
		ll maxn=-11111111;
		for(int i = 1 ;i<=n;i++){
			int x;
			cin>>x;
			maxn=max(maxn,x);
		}
		cout<<maxn;
	}else if(m==2){
		ll maxn=-11111111;
		for(int i = 1 ;i<=n;i++){
			cin>>a[i];
		}
		for(int i = 1 ;i<=n;i++){
			for(int j= 1 ;j<=n;j++){
		   		if(i==j) continue;
		   		maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}else if(m<=n){
		ll maxn=-11111111;
		for(int i = 1 ;i<=n;i++){
			cin>>a[i];
		}
		for(int i = 1 ;i<=n;i++){
			if(m>=2){
				for(int j = 1 ;j<=n;j++){
					if(m>=3){
						for(int k = 1 ;k<=n;k++){
							if(m>=4){
								for(int l = 1 ;l<=n;l++){
									if(m>=5){
										for(int b = 1 ;b<=n;b++){
											if(m>=6){
												for(int v = 1 ;v<=n;v++){
													if(m>=7){
														for(int c = 1 ;c<=n;c++){
															if(m>=8){
																for(int x = 1 ;x<=n;x++){
																	if(m>=9){
																		for(int z = 1 ;z<=n;z++){
																			if(m>=10){
																				for(int h = 1 ;h<=n;h++){
																					if(m>=11){
																						for(int g = 1 ;g<=n;g++){
																							if(m>=12){
																								for(int f = 1 ;f<=n;f++){
																									if(m>=13){
																										for(int d = 1 ;d<=n;d++){
																											if(m>=14){
																												for(int s = 1 ;s<=n;s++){
																													if(m>=15){
																														for(int h = 1 ;h<=n;h++){
																															
																														}
																													}else{
																														if(i==s||j==s||k==s||l==s||b==s||c==s||x==s||z==s||h==s||g==s||f==s||d==s||i==d||j==d||k==d||l==d||b==d||v==d||c==d||x==d||z==d||h==d||g==d||f==d||i==f||j==f||k==f||l==f||b==f||v==f||c==f||x==f||z==f||h==f||g==f||i==j||i==k||j==k||i==l||j==l||k==l||i==b||j==b||k==b||l==b||i==v||j==v||k==v||l==v||b==v||i==c||j==c||b==c||k==c||l==c||i==x||j==x||k==x|b==x||v==x||c==x||l==x||i==z||j==z||k==z||l==z||b==z||v==z||c==z||x==z||i==h||j==h||k==h||l==h||b==h||v==h||c==h||x==h||z==h||i==g||j==g||k==g||l==g||b==g||v==g||c==g||x==g||z==g) continue;
																														maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[b]&a[v]&a[c]&a[x]&a[z]&a[h]&a[g]&a[f]&a[d]&a[s]);
																													}
																												}
																											}else{
																												if(i==d||j==d||k==d||l==d||b==d||v==d||c==d||x==d||z==d||h==d||g==d||f==d||i==f||j==f||k==f||l==f||b==f||v==f||c==f||x==f||z==f||h==f||g==f||i==j||i==k||j==k||i==l||j==l||k==l||i==b||j==b||k==b||l==b||i==v||j==v||k==v||l==v||b==v||i==c||j==c||b==c||k==c||l==c||i==x||j==x||k==x|b==x||v==x||c==x||l==x||i==z||j==z||k==z||l==z||b==z||v==z||c==z||x==z||i==h||j==h||k==h||l==h||b==h||v==h||c==h||x==h||z==h||i==g||j==g||k==g||l==g||b==g||v==g||c==g||x==g||z==g) continue;
																												maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[b]&a[v]&a[c]&a[x]&a[z]&a[h]&a[g]&a[f]&a[d]);
																											}
																										}
																									}else{
																										if(i==f||j==f||k==f||l==f||b==f||v==f||c==f||x==f||z==f||h==f||g==f||i==j||i==k||j==k||i==l||j==l||k==l||i==b||j==b||k==b||l==b||i==v||j==v||k==v||l==v||b==v||i==c||j==c||b==c||k==c||l==c||i==x||j==x||k==x|b==x||v==x||c==x||l==x||i==z||j==z||k==z||l==z||b==z||v==z||c==z||x==z||i==h||j==h||k==h||l==h||b==h||v==h||c==h||x==h||z==h||i==g||j==g||k==g||l==g||b==g||v==g||c==g||x==g||z==g) continue;
																										maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[b]&a[v]&a[c]&a[x]&a[z]&a[h]&a[g]&a[f]);
																									}
																								}
																							}else{
																								if(i==j||i==k||j==k||i==l||j==l||k==l||i==b||j==b||k==b||l==b||i==v||j==v||k==v||l==v||b==v||i==c||j==c||b==c||k==c||l==c||i==x||j==x||k==x|b==x||v==x||c==x||l==x||i==z||j==z||k==z||l==z||b==z||v==z||c==z||x==z||i==h||j==h||k==h||l==h||b==h||v==h||c==h||x==h||z==h||i==g||j==g||k==g||l==g||b==g||v==g||c==g||x==g||z==g) continue;
																								maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[b]&a[v]&a[c]&a[x]&a[z]&a[h]&a[g]);
																							}
																						}
																					}else{
																						if(i==j||i==k||j==k||i==l||j==l||k==l||i==b||j==b||k==b||l==b||i==v||j==v||k==v||l==v||b==v||i==c||j==c||b==c||k==c||l==c||i==x||j==x||k==x|b==x||v==x||c==x||l==x||i==z||j==z||k==z||l==z||b==z||v==z||c==z||x==z||i==h||j==h||k==h||l==h||b==h||v==h||c==h||x==h||z==h) continue;
																						maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[b]&a[v]&a[c]&a[x]&a[z]&a[h]);
																					}
																				}
																			}else{
																				if(i==j||i==k||j==k||i==l||j==l||k==l||i==b||j==b||k==b||l==b||i==v||j==v||k==v||l==v||b==v||i==c||j==c||b==c||k==c||l==c||i==x||j==x||k==x|b==x||v==x||c==x||l==x||i==z||j==z||k==z||l==z||b==z||v==z||c==z||x==z) continue;
																				maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[b]&a[v]&a[c]&a[x]&a[z]);
																			}
																		}
																	}else{
																		if(i==j||i==k||j==k||i==l||j==l||k==l||i==b||j==b||k==b||l==b||i==v||j==v||k==v||l==v||b==v||i==c||j==c||b==c||k==c||l==c||i==x||j==x||k==x|b==x||v==x||c==x||l==x) continue;
																		maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[b]&a[v]&a[c]&a[x]);
																	}
																}
															}else{
																if(i==j||i==k||j==k||i==l||j==l||k==l||i==b||j==b||k==b||l==b||i==v||j==v||k==v||l==v||b==v||i==c||j==c||b==c||k==c||l==c) continue;
																maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[b]&a[v]&a[c]);
															}
														}
													}else{
														if(i==j||i==k||j==k||i==l||j==l||k==l||i==b||j==b||k==b||l==b||i==v||j==v||k==v||l==v||b==v) continue;
														maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[b]&a[v]);
													}
												}
											}else{
												if(i==j||i==k||j==k||i==l||j==l||k==l||i==b||j==b||k==b||l==b) continue;
												maxn=max(maxn,a[i]&a[j]&a[k]&a[l]&a[b]);
											}
										}
									}else{
										if(i==j||i==k||j==k||i==l||j==l||k==l) continue;
										maxn=max(maxn,a[i]&a[j]&a[k]&a[l]);
									}
								}
							}else{
								if(i==j||i==k||j==k) continue;
								maxn=max(maxn,a[i]&a[j]&a[k]);
							}
						}
					}else{
						if(i==j) continue;
						maxn=max(maxn,a[i]&a[j]);
					}
				}
			}else{
				maxn=max(maxn,a[i]);
			}
		}
		cout<<maxn;
	} else{
		for(int i = 1 ;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		ll ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

/***
2026 CCF 非专业级软件能力认证CSP-J/S 2026 第二轮
入门组按位与（and）
按位与（and）
【题目描述】
小R有n个非负整数a1,a2,...,an。
小X给了小R一个正整数m，并要求小R从这n个非负整数中选出.恰.好m个，
使得选出的m个数的.二.进 .制 .按 .位 .与的值最大。
你需要帮助小R求出，他能选出的m个数的按位与的最大值。
【输入格式】
从文件and.in 中读入数据。
输入的第一行包含两个正整数n,m。
输入的第二行包含n个非负整数a1,a2,...,an，依次表示小 R的n个非负整数。
【输出格式】
输出到文件and.out 中。
输出一行一个非负整数，表示小R能选出的m个数的按位与的最大值。
【样例1输入】
1 4 2
2 3 15 12 12
【样例1输出】
1 12
***/
