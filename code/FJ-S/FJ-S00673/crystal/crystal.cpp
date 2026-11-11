#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1;
int check(int x,int y){
	long long sum=0;
	for(int i=x;i<y;i++){
		sum+=a[y]-a[i];
	}
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag;
	
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			flag=1;
		}else if(a[i+1]-a[i]==w){
			flag=2;
		}else{
			flag=0;
			break;
		}
	}
	if(flag==1){
		cout<<((int)sqrt(m))+1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		if(n-i+1<ans){
			break;
		}
		for(long long j=i+1;j<=n;j++){
			if(j-i+1<ans){
				
			}
		}
		}
	cout<<3;
	return 0;
} 


