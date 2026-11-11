#include <bits/stdc++.h>
using namespace std;
long long n,m,s,a[200010],k,l,r,q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4){
			k=1;
		}
		else if(a[i]==3){
			l++;
		}
		else if(a[i]==2){
			r++;
		}
		else{
			q++;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			s=max(s,a[i]);
		}
	}
	else if(m==n){
		s=a[1];
		for(int i=2;i<=n;i++){
			s=(s&a[i]);
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=max(s,(a[i]&a[j]));
			}
		}
	}
	else if(k!=1){
		if(l>=m){
			s=3;
		}
		else if(l+r>=m){
			s=2;
		}
		else if(l+q>=m){
			s=1;
		}
		else{
			s=0;
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					s=max(s,(a[i]&a[j]&a[k]));
				}
			}
		}
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						s=max(s,(a[i]&a[j]&a[k]&a[o]));
					}
				}
			}
		}
	}
	else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
							s=max(s,(a[i]&a[j]&a[k]&a[o]&a[p]));
						}
					}
				}
			}
		}
	}
	else if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
							for(int t=p+1;t<=n;t++){
								s=max(s,(a[i]&a[j]&a[k]&a[o]&a[p]&a[t]));
							}
						}
					}
				}
			}
		}
	}
	else if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
							for(int t=p+1;t<=n;t++){
								for(int u=t+1;u<=n;u++){
									s=max(s,(a[i]&a[j]&a[k]&a[o]&a[p]&a[t]&a[u]));
								}
							}
						}
					}
				}
			}
		}
	}
	else if(m==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
							for(int t=p+1;t<=n;t++){
								for(int u=t+1;u<=n;u++){
									for(int v=u+1;v<=n;v++){
										s=max(s,(a[i]&a[j]&a[k]&a[o]&a[p]&a[t]&a[u]&a[v]));
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else{
		sort(a+1,a+n+1);
		s=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			s=(s&a[i]);
		}
	}
	cout<<s;
	return 0;
}
