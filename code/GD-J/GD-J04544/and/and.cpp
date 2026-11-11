#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long n,m,a[N],ans,maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	ans=a[1];
	for(int i=2;i<=n;i++)ans&=a[i];
	if(m==n){
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			int b=ans;
			int s=b&a[i];
			if(s>maxn)maxn=s;
		}
		cout<<maxn;
	}
	else {
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int s=a[i]&a[2];
				if(s>maxn)maxn=s;
			}
		}
		cout<<maxn;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
