#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int cnt=-1;
		for(int i=1;i<=n;i++){
			cnt=max(cnt,a[i]);
		}
		cout<<cnt;
	}else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}else if(m==2){
		int res=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i) res=max(res,a[i]&a[j]);
			}
		}
		cout<<res;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
