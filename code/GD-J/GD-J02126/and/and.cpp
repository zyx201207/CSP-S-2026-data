#include<bits/stdc++.h>
int n,m;
int a[200005],and_a[200005],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		if(i>0) and_a[i]=and_a[i-1] & a[i];
		if(i==0) and_a[i]=a[i];
	}
	if(m==1){
		for (int i=0;i<n;i++) ans=std::max(ans,a[i]);
	}
	if(m==2){
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				ans=std::max(a[i] & a[j],ans);
			}
		}
	}
	if(m==n){
		ans=a[0];
		for (int i=1;i<n;i++) ans=ans & a[i];
	}
//	if(m==n-1 && m!=1){
//		for (int i=0;i<n;i++) ans=std::max(ans,and_a[n-1] | a[i]);
//	}
	if(n<=20){
		if(m==3){
			for (int i=0;i<n-2;i++){
				for (int j=i+1;j<n-1;j++){
					for (int k=j+1;k<n;k++) ans=std::max(ans,a[i] & a[j] & a[k]);
				}
			}
		}
		if(m==4){
			for (int i=0;i<n-3;i++){
				for (int j=i+1;j<n-2;j++){
					for (int k=j+1;k<n-1;k++){
						for (int w=k+1;w<n;w++) ans=std::max(ans,a[i] & a[j] & a[k] & a[w]);
					}
				}
			}
		}
		if(m==5){
			for (int i=0;i<n-4;i++){
				for (int j=i+1;j<n-3;j++){
					for (int k=j+1;k<n-2;k++){
						for (int w=k+1;w<n-1;w++){
							for (int v=w+1;v<n;v++) ans=std::max(ans,a[i] & a[j] & a[k] & a[w] & a[v]);
						}
					}
				}
			}
		}
		if(m==6){
			for (int i=0;i<n-5;i++){
				for (int j=i+1;j<n-4;j++){
					for (int k=j+1;k<n-3;k++){
						for (int w=k+1;w<n-2;w++){
							for (int v=w+1;v<n-1;v++){
								for (int u=v+1;u<n;u++) ans=std::max(ans,a[i] & a[j] & a[k] & a[w] & a[v] & a[u]);
							}
						}
					}
				}
			}
		}
	if(m==7){
			for (int i=0;i<n-6;i++){
				for (int j=i+1;j<n-5;j++){
					for (int k=j+1;k<n-4;k++){
						for (int w=k+1;w<n-3;w++){
							for (int v=w+1;v<n-2;v++){
								for (int u=v+1;u<n-1;u++){
									for (int x=u+1;x<n;x++) ans=std::max(ans,a[i] & a[j] & a[k] & a[w] & a[v] & a[u] & a[x]);
								}
							}
						}
					}
				}
			}
		}
	if(m==8){
			for (int i=0;i<n-7;i++){
				for (int j=i+1;j<n-6;j++){
					for (int k=j+1;k<n-5;k++){
						for (int w=k+1;w<n-4;w++){
							for (int v=w+1;v<n-3;v++){
								for (int u=v+1;u<n-2;u++){
									for (int x=u+1;x<n-1;x++){
										for (int y=x+1;y<n;y++) ans=std::max(ans,a[i] & a[j] & a[k] & a[w] & a[v] & a[u] & a[x]);
									}
								}
							}
						}
					}
				}
			}
		}
	if(m==9){
			for (int i=0;i<n-8;i++){
				for (int j=i+1;j<n-7;j++){
					for (int k=j+1;k<n-6;k++){
						for (int w=k+1;w<n-5;w++){
							for (int v=w+1;v<n-4;v++){
								for (int u=v+1;u<n-3;u++){
									for (int x=u+1;x<n-2;x++){
										for (int y=x+1;y<n-1;y++){
											for (int z=y+1;z<n;z++) ans=std::max(ans,a[i] & a[j] & a[k] & a[w] & a[v] & a[u] & a[x] &a[z]);
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
	else{
		std::sort(a,a+n);
		ans=a[n-m];
	}
	printf("%d",ans);
	return 0;
}
