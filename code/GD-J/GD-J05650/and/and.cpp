#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int>a(n+1);
	int maxx=0;
	int ans=2147483647;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxx=max(maxx,a[i]);
		ans&=a[i];
	}
	sort(a.begin()+1,a.begin()+n+1,cmp);
	if(n==m){
		cout << ans;
	}else if(m==2){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=max(cnt,a[i]&a[j]);
			}
		}
		cout << cnt;
	}else if(m==3){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					cnt=max(cnt,a[i]&a[j]&a[k]);
				}
			}
		}
		cout << cnt;
	}else if(m==4){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int x=k+1;x<=n;x++){
						cnt=max(cnt,a[i]&a[j]&a[k]&a[x]);
					}
				}
			}
		}
		cout << cnt;
	}else if(m==5){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int x=k+1;x<=n;x++){
						for(int y=x+1;y<=n;y++){
							cnt=max(cnt,a[i]&a[j]&a[k]&a[x]&a[y]);
						}
					}
				}
			}
		}
		cout << cnt;
	}else if(m==6){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int x=k+1;x<=n;x++){
						for(int y=x+1;y<=n;y++){
							for(int z=y+1;z<=n;z++){
								cnt=max(cnt,a[i]&a[j]&a[k]&a[x]&a[y]&a[z]);
							}
						}
					}
				}
			}
		}
		cout << cnt;
	}else if(m==7){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int x=k+1;x<=n;x++){
						for(int y=x+1;y<=n;y++){
							for(int z=y+1;z<=n;z++){
								for(int p=z+1;p<=n;p++){
									cnt=max(cnt,a[i]&a[j]&a[k]&a[x]&a[y]&a[z]&a[p]);
								}
							}
						}
					}
				}
			}
		}
		cout << cnt;
	}else if(m==1) cout << maxx;
	else cout << a[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

