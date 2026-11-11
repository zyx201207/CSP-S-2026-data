#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==1){
		for(int i=0;i<n;i++){
			if(ans<a[i]) ans=a[i];
		}
	} else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				if(ans<(a[i]&a[j])) ans=(a[i]&a[j]);
			}
		}
	} else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				for(int k=0;k<n;k++){
					if(i==k||j==k) continue;
					if(ans<(a[i]&a[j]&a[k])) ans=(a[i]&a[j]&a[k]);
				}
			}
		}
	} else if(m==4){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				for(int k=0;k<n;k++){
					if(i==k||j==k) continue;
					for(int l=0;l<n;l++){
						if(i==l||j==l||k==l) continue;
						if(ans<(a[i]&a[j]&a[k]&a[l])) ans=(a[i]&a[j]&a[k]&a[l]);
					}
				}
			}
		}
	} else if(m==5){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				for(int k=0;k<n;k++){
					if(i==k||j==k) continue;
					for(int l=0;l<n;l++){
						if(i==l||j==l||k==l) continue;
						for(int o=0;o<n;o++){
							if(i==o||j==o||k==o||l==o) continue;
							if(ans<(a[i]&a[j]&a[k]&a[l]&a[o])) ans=(a[i]&a[j]&a[k]&a[l]&a[o]);
						}
					}
				}
			}
		}
	} else if(m==6){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				for(int k=0;k<n;k++){
					if(i==k||j==k) continue;
					for(int l=0;l<n;l++){
						if(i==l||j==l||k==l) continue;
						for(int o=0;o<n;o++){
							if(i==o||j==o||k==o||l==o) continue;
							for(int p=0;p<n;p++){
								if(i==p||j==p||k==p||l==p||o==p) continue;
								if(ans<(a[i]&a[j]&a[k]&a[l]&a[o]&a[p])) ans=(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]);
							}
						}
					}
				}
			}
		}
	} else if(m==7){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				for(int k=0;k<n;k++){
					if(i==k||j==k) continue;
					for(int l=0;l<n;l++){
						if(i==l||j==l||k==l) continue;
						for(int o=0;o<n;o++){
							if(i==o||j==o||k==o||l==o) continue;
							for(int p=0;p<n;p++){
								if(i==p||j==p||k==p||l==p||o==p) continue;
								for(int q=0;q<n;q++){
									if(i==q||j==q||k==q||l==q||o==q||p==q) continue;
									if(ans<(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q])) ans=(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]);
								}
							}
						}
					}
				}
			}
		}
	} else if(m==8){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				for(int k=0;k<n;k++){
					if(i==k||j==k) continue;
					for(int l=0;l<n;l++){
						if(i==l||j==l||k==l) continue;
						for(int o=0;o<n;o++){
							if(i==o||j==o||k==o||l==o) continue;
							for(int p=0;p<n;p++){
								if(i==p||j==p||k==p||l==p||o==p) continue;
								for(int q=0;q<n;q++){
									if(i==q||j==q||k==q||l==q||o==q||p==q) continue;
									for(int r=0;r<n;r++){
										if(i==r||j==r||k==r||l==r||o==r||p==r||q==r) continue;
										if(ans<(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r])) ans=(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]);
									}
								}
							}
						}
					}
				}
			}
		}
	} else if(m==9){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				for(int k=0;k<n;k++){
					if(i==k||j==k) continue;
					for(int l=0;l<n;l++){
						if(i==l||j==l||k==l) continue;
						for(int o=0;o<n;o++){
							if(i==o||j==o||k==o||l==o) continue;
							for(int p=0;p<n;p++){
								if(i==p||j==p||k==p||l==p||o==p) continue;
								for(int q=0;q<n;q++){
									if(i==q||j==q||k==q||l==q||o==q||p==q) continue;
									for(int r=0;r<n;r++){
										if(i==r||j==r||k==r||l==r||o==r||p==r||q==r) continue;
										for(int s=0;s<n;s++){
											if(i==s||j==s||k==s||l==s||o==s||p==s||q==s||r==s) continue;
											if(ans<(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s])) ans=(a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]);
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
	return 0;
}