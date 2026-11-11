#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=5,m=6,max=0,c;
	bool flag=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	c=a[2]-a[1];
//	for(int i=2;i<=n;i++){
//		if(a[i]-a[i-1]==c){
//			flag=true;
//			continue;
//		}
//		flag=false;
//	}
	if(flag){
		b[1]=0;
		for(int i=2;i<=n;i++){
			b[i]=b[i-1]+a[i]-1;
		}
		for(int i=1;i<=n;i++){
			if(m>=b[i]){
				max=i;
			}
		}
		cout<<max;
		return 0;
	}
	
	return 0;
}
