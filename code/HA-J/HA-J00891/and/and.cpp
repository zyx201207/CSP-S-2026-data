#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[22222],c=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin << a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>c){
				c=a[i];
			}
		}
	}
	else if(m==2){
		for(int =1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i&j>c){
					c=i&j;
				}
			}
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i&j&k>c){
						c=i&j&k;
					}
				}
			}
		}
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						if(i&j&k&l>c){
							c=i&j&k&l;
						}
					}
				}
			}
		}
	}
	else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						for(int o=1;o<=n;o++){
							if(i&j&k&l&o>c){
								c=i&j&k&l&o;
							}
						}
					}
				}
			}
		}
	}
	else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						for(int o=1;o<=n;o++){
							for(int p=1;p<=n;p++){
								if(i&j&k&l&o&p>c){
								c=i&j&k&l&o&p;
							}
							}
						}
					}
				}
			}
		}
	}
	cout << c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
