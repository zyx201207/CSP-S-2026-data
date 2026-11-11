#include <bits/stdc++.h> 
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	long long t=0;
	int x1,x2;
	char y11,y2;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i%2){
			cin>>x1>>y11;
			t+=x1;
		}
		else{
			cin>>x2>>y2;
			t+=x2;
		}
		if(x1==1||x2==1){
			sum++;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<min(x1,x2);
		return 0;
	}
	if(sum==n){
		cout<<n/2;
		return 0;
	} 
	cout<<t/2;
//	if(n/2==0){
//		z=n/2;
//	}
//	else{
//		z=n/2+1;
//	}
//	int i=0;
//	while(z<=n){
//		i++;
//		
//	}
}
