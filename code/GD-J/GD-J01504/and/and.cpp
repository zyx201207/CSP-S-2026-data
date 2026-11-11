#include<bits/stdc++.h>
using namespace std;
long long a[222222];
int n,m;
void dfs(){
	long long maxn=-114514;
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i==j||j==k||i==k)continue;
					maxn=max(maxn,a[i]&a[j]&a[k]);
				}
			}
		}
	}else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int q=1;q<=n;q++){
						if(i==j||i==k||i==q||j==k||j==q||k==q)continue;
						maxn=max(maxn,a[i]&a[j]&a[k]&a[q]);
					}
				}
			}
		}
	}else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int q=1;q<=n;q++){
						for(int h=1;h<=n;h++){
							if(i==j||i==k||i==q||i==h||j==k||j==q||j==h||k==q||k==h||q==h)continue;
							maxn=max(maxn,a[i]&a[j]&a[k]&a[q]&a[h]);
						}
					}
				}
			}
		}
	}else{
		maxn=1;
	}
	cout<<maxn;
}
bool check(){
	bool flag_4=true;
	for(int i=1;i<=n;i++){
		if(a[i]>=4)flag_4=false;
	}
	return flag_4;
}
bool check_13yl(int n){
	bool flag=true;
	for(int i=1;i<=n;i++){
		bool f=false;
		long long sum=1;
		for(int k=1;k<=25;k++){
			for(int j=1;j<=k;j++){
				sum*=2;
			}
			if(a[i]+1==sum){
				f=true;
				break;
			}
		}
		if(!f)return false;
	} 
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxn=-114514,AWY_1,AWY_2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)AWY_1=a[i];
		else AWY_1&=a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}else if(m==n){
		cout<<AWY_1;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				AWY_2=max(AWY_2,a[i]&a[j]);
			}
		}
		cout<<AWY_2;
		return 0;
	}else if(check_13yl(n)){
		sort(a+1,a+n+1);
		cout<<a[m];
	}else if(n<=20){
		dfs();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
