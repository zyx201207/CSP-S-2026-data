#include<bits/stdc++.h>

using namespace std;
const int N=2e5;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		cout<<maxn;
	}
	if(m==2){
		for(int a1=1;a1<=n;a1++){
			for(int a2=a1+1;a2<=n;a2++){
				if((a[a1]&a[a2])>maxn){
					maxn=(a[a1]&a[a2]);
				}
			}
		}
		cout<<maxn;
	}
	if(m==3){
		for(int a1=1;a1<=n;a1++){
			for(int a2=a1+1;a2<=n;a2++){
				for(int a3=a2+1;a3<=n;a3++){
					if((a[a1]&a[a2]&a[a3])>maxn){
						maxn=(a[a1]&a[a2]&a[a3]);
					}
				}
			}
		}
		cout<<maxn;
	}
	if(m==4){
		for(int a1=1;a1<=n;a1++){
			for(int a2=a1+1;a2<=n;a2++){
				for(int a3=a2+1;a3<=n;a3++){
					for(int a4=a3+1;a4<=n;a4++){
						if((a[a1]&a[a2]&a[a3]&a[a4])>maxn){
							maxn=(a[a1]&a[a2]&a[a3]&a[a4]);
						}
					}
				}
			}
		}
		cout<<maxn;
	}
	if(m==5){
		for(int a1=1;a1<=n;a1++){
			for(int a2=a1+1;a2<=n;a2++){
				for(int a3=a2+1;a3<=n;a3++){
					for(int a4=a3+1;a4<=n;a4++){
						for(int a5=a4+1;a5<=n;a5++){
							if((a[a1]&a[a2]&a[a3]&a[a4]&a[a5])>maxn){
								maxn=(a[a1]&a[a2]&a[a3]&a[a4]&a[a5]);
							}
						}
					}
				}
			}
		}
		cout<<maxn;
	}
	if(m==6){
		for(int a1=1;a1<=n;a1++){
			for(int a2=a1+1;a2<=n;a2++){
				for(int a3=a2+1;a3<=n;a3++){
					for(int a4=a3+1;a4<=n;a4++){
						for(int a5=a4+1;a5<=n;a5++){
							for(int a6=a5+1;a6<=n;a6++){
								if((a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6])>maxn){
									maxn=(a[a1]&a[a2]&a[a3]&a[a4]&a[a5]&a[a6]);
								}
							}
						}
					}
				}
			}
		}
		cout<<maxn;
	}
	return 0;
}
