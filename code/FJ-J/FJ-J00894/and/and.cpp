#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
bool find1=true;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			find1=false;
		}
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	else if(m==2){
		int k=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				k=max(k,a[i]&a[j]);
			}
		}
		cout<<k;
	}
	else if(m==n){
		int k=a[1];
		for(int i=2;i<=n;i++){
			k&=a[i];
		}
		cout<<k;
	}
	else if(m==3){
		int k=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int x3=j+1;x3<=n;x3++){
					k=max(k,a[i]&a[j]&a[x3]);
				}
			}
		}
		cout<<k;
	}
	else if(m==4){
		int k=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int x3=j+1;x3<=n-1;x3++){
					for(int x4=x3+1;x4<=n;x4++){
						k=max(k,a[i]&a[j]&a[x3]&a[x4]);
					}
				}
			}
		}
		cout<<k;
	}
	else if(m==5){
		int k=0;
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int x3=j+1;x3<=n-2;x3++){
					for(int x4=x3+1;x4<=n-1;x4++){
						for(int x5=x4+1;x5<=n;x5++){
							k=max(k,a[i]&a[j]&a[x3]&a[x4]&a[x5]);
						}
					}
				}
			}
		}
		cout<<k;
	}
	else if(m==6){
		int k=0;
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int x3=j+1;x3<=n-3;x3++){
					for(int x4=x3+1;x4<=n-2;x4++){
						for(int x5=x4+1;x5<=n-1;x5++){
							for(int x6=x5+1;x6<=n;x6++){
								k=max(k,a[i]&a[j]&a[x3]&a[x4]&a[x5]&a[x6]);
							}
						}
					}
				}
			}
		}
		cout<<k;
	}
	else if(m==7){
		int k=0;
		for(int i=1;i<=n-6;i++){
			for(int j=i+1;j<=n-5;j++){
				for(int x3=j+1;x3<=n-4;x3++){
					for(int x4=x3+1;x4<=n-3;x4++){
						for(int x5=x4+1;x5<=n-2;x5++){
							for(int x6=x5+1;x6<=n-1;x6++){
								for(int x7=x6+1;x7<=n;x7++){
									k=max(k,a[i]&a[j]&a[x3]&a[x4]&a[x5]&a[x6]&a[x7]);
								}
							}
						}
					}
				}
			}
		}
		cout<<k;
	}
	else if(m==8){
		int k=0;
		for(int i=1;i<=n-7;i++){
			for(int j=i+1;j<=n-6;j++){
				for(int x3=j+1;x3<=n-5;x3++){
					for(int x4=x3+1;x4<=n-4;x4++){
						for(int x5=x4+1;x5<=n-3;x5++){
							for(int x6=x5+1;x6<=n-2;x6++){
								for(int x7=x6+1;x7<=n-1;x7++){
									for(int x8=x7+1;x8<=n;x8++){
										k=max(k,a[i]&a[j]&a[x3]&a[x4]&a[x5]&a[x6]&a[x7]&a[x8]);
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<k;
	}
	else{
		cout<<a[n]&a[n-1]&a[n-2];
	}
	return 0;
}
