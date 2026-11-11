#include<bits/stdc++.h>
using namespace std;
const int M=1e6;
long long n,m,maxn;
int a[M];
int twice(int x){
	int num[8]={0,0,0,0,0,0,0,0};
	for(int i=8;i>=0;i--){
		while(x>0){
			num[i]=x%2;
			x/=2;
			if(x<1){
				break;
			}
		}
	}
	for(int i=0;i<=8;i++){
		return num[i];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=a[i]&a[j];
			maxn=max((a[i]&a[j]),(a[i]&a[j]));
		}
	}
	cout<<maxn;
	return 0;
} 
