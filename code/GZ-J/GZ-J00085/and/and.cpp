//GZ-J00085 贵阳市第二实验中学 杨浩然
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=-1;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]!=a[j]){
					cnt=max(cnt,a[i]&a[j]);
				}
			}
		}
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			cnt&=a[i]; 
		}
	}
	if(m==1){
		sort(a+1,a+1+n);
		cnt=a[n];
	}else{
		sort(a+1,a+1+n);
		cnt=a[n-m+1];
	}
	cout<<cnt;
	return 0;
}

