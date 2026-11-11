#include<bits/stdc++.h>
using namespace std;

int const M=1e7;
long long a[M];
int pw[31];
int n,m,ans=-1;
int f(int l,int c,int zh){
	if(c==m) return zh;
	for(int i=l;i<=n;i++){
		ans=max(f(i+1,c+1,zh&a[i]),ans);
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	pw[0]=1;
	for(int i=1;i<=30;i++){
		pw[i]=pw[i-1]*2;
	}
	int A=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++)
			if(pw[j]-a[i]==1){
				A++;
			}
	}
	if(A==n){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	else if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			int x=a[i]&a[j];
			ans=max(x,ans);
			}
		}
		cout<<ans;
	}
	else{
		cout<<f(1,1,a[1]);
	}
	return 0;
}
