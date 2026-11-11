#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out ","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int sum=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			sum=max(sum,a[i]);
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=a[i]&a[j];
				sum=max(x,sum);
			}
		}
	}else if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			int x=sum&a[i];
			sum=x;
		}
	}
	cout<<sum;
	return 0; 
}

