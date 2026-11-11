#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k,a[100010];
	cin>>n>>k;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	if(k == n){
		int s = (a[0]&a[1]);
		for(int i = 2;i<n;i++){
			s = a[i]&a[i-1];
		}
		cout<<s;
		return 0;
	}
	int maxx = -1010;
	if(k == 2){
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				if((a[i]&a[j]) > maxx)maxx = a[i]&a[j];
			}
		}
	}else if(k == 3){
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				for(int k = j+1;k<n;k++){
					if((a[i]&a[j]&a[k]) > maxx){
						maxx = a[i]&a[j]&a[k];
					}
				}
			}
		}
	}else if(k == 4){
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				for(int k = j+1;k<n;k++){
					for(int m =k+1;m<n;m++){
						if((a[i]&a[j]&a[k]&a[m]) > maxx){
							maxx = a[i]&a[j]&a[k]&a[m];
						}
					}
				}
			}
		}
	}else if(k == 5){
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				for(int k = j+1;k<n;k++){
					for(int m =k+1;m<n;m++){
						for(int h = m+1;h<n;h++){
							if((a[i]&a[j]&a[k]&a[m]&a[h]) > maxx){
								maxx = a[i]&a[j]&a[k]&a[m]&a[h];
							}
						}
					}
				}
			}
		}
	}else if(k == 6){
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				for(int k = j+1;k<n;k++){
					for(int m =k+1;m<n;m++){
						for(int h = m+1;h<n;h++){
							for(int y = h+1;y<n;y++){
								if((a[i]&a[j]&a[k]&a[m]&a[h]&a[y]) > maxx){
									maxx = a[i]&a[j]&a[k]&a[m]&a[h]&a[y];
								}
							}
						}
					}
				}
			}
		}
	}else if(k == 7){
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				for(int k = j+1;k<n;k++){
					for(int m =k+1;m<n;m++){
						for(int h = m+1;h<n;h++){
							for(int y = h+1;y<n;y++){
								for(int x = y+1;x<n;x++){
									if((a[i]&a[j]&a[k]&a[m]&a[h]&a[y]&a[x]) > maxx){
										maxx = a[i]&a[j]&a[k]&a[m]&a[h]&a[y]&a[x];
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}
