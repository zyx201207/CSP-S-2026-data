#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long f=0,fi;
	for(int i=1;i<=n;i++){
		long long h=pow(2,i);
		if(h==n){
			fi=i;
			f=1;
			break;
		}
	}
	if(m==1){
		long long max1=0;
		for(int i=1;i<=n;i++){
			max1=max(max1,(long long)a[i]);
		}
		cout<<max1;
	}else if(m==2){
		long long max1=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				max1=max(max1,(long long)a[i]&a[j]);
			}
		}
		cout<<max1;
	}else if(n==m){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(n-1==m){
		long long min1=INT_MAX,ans;
		for(int i=1;i<=n;i++){
			min1=min(min1,(long long)a[i]);
		}
		bool f=0;
		if(min1==a[1]){
			ans=a[2];
		}else{
			ans=a[1];
		}
		for(int i=1;i<=n;i++){
			if(f==0&&a[i]==min1){
				f=1;
				continue;
			}else{
				ans&=a[i];
			}
		}
	}else if(f==1){
		cout<<pow(2,fi-m+1)-1;
	}else{
		long long max1=0;
		for(int i=1;i<=n;i++){
			max1=max(max1,(long long)a[i]);
		}
		long long f=0,fi;
		for(int i=1;i<=n;i++){
			long long h=pow(2,i);
			if(h==max1+1){
				fi=i;
				f=1;
				break;
			}
		}
		cout<<pow(2,fi-m+1)-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
