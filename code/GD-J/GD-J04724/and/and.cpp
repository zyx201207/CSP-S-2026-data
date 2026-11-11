#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,maxn;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	vector<int> q;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		q.push_back(a);
	}
	if(m==1){
		for(int i=0;i<n;i++){
			maxn=max(maxn,q.at(i));
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				maxn=max(maxn,q.at(i)&q.at(j));
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					maxn=max(maxn,q.at(i)&q.at(j)&q.at(k));
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==4){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						maxn=max(maxn,q.at(i)&q.at(j)&q.at(k)&q.at(l));
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==5){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int u=l+1;u<n;u++){
							maxn=max(maxn,q.at(i)&q.at(j)&q.at(k)&q.at(l)&q.at(u));
						}	
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==6){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int u=l+1;u<n;u++){
							for(int v=u+1;v<n;v++){
								maxn=max(maxn,q.at(i)&q.at(j)&q.at(k)&q.at(l)&q.at(u)&q.at(v));
							}
						}	
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==7){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int u=l+1;u<n;u++){
							for(int v=u+1;v<n;v++){
								for(int w=v+1;w<n;w++){
									maxn=max(maxn,q.at(i)&q.at(j)&q.at(k)&q.at(l)&q.at(u)&q.at(v)&q.at(w));
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
	if(m==8){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int u=l+1;u<n;u++){
							for(int v=u+1;v<n;v++){
								for(int w=v+1;w<n;w++){
									for(int x=w+1;x<n;x++){
										maxn=max(maxn,q.at(i)&q.at(j)&q.at(k)&q.at(l)&q.at(u)&q.at(v)&q.at(w)&q.at(x));
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
	if(m==9){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int u=l+1;u<n;u++){
							for(int v=u+1;v<n;v++){
								for(int w=v+1;w<n;w++){
									for(int x=w+1;x<n;x++){
										for(int y=x+1;y<n;y++){
											maxn=max(maxn,q.at(i)&q.at(j)&q.at(k)&q.at(l)&q.at(u)&q.at(v)&q.at(w)&q.at(x)&q.at(y));
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
	if(m==10){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int u=l+1;u<n;u++){
							for(int v=u+1;v<n;v++){
								for(int w=v+1;w<n;w++){
									for(int x=w+1;x<n;x++){
										for(int y=x+1;y<n;y++){
											for(int z=y+1;z<n;z++){
												maxn=max(maxn,q.at(i)&q.at(j)&q.at(k)&q.at(l)&q.at(u)&q.at(v)&q.at(w)&q.at(x)&q.at(y)&q.at(z));
											}
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
//	int now=0,prev=0,cnt=0;
//	now=q.front();
//	q.erase(q.begin());
//	while(m!=0){
//		prev=now;
//		cout<<prev<<endl;
//		now&=q.front();
//		cout<<now<<endl;
//		q.erase(q.begin());
//		maxn=max(maxn,now);
//		cout<<maxn<<endl;
//		now=prev;
//		q.push_back(prev);
//		cnt++;
//		cout<<cnt<<endl;
//		if(cnt==n-1){
//			m--;
//			cout<<m<<endl;
//			now=maxn;
//			auto it=find(q.begin(),q.end(),prev);
//			q.erase(it);
//			cnt=0;
//		}
//	}
//	cout<<maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
