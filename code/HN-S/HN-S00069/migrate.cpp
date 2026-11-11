#include<bits/stdc++.h>
using namespace std;
int a[2000010],b[2000010];
void v(){
	int n,d,Answer=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		b[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1-i;
	}
	for(int i=1;i<=n;i++){
		if(b[i]>2||b[i+1]>2||b[i+2]>2){
			Answer+=n-i-2;
		}
		for(int j=i+3;j<=n;j++){
			if(b[j]>2){
				Answer+=n-j+1;
				break;
			}
		}
	}
	cout<<Answer<<'\n';
}
int main(){
	int c,t;
	cin>>c>>t;
	while(t--){
		v();
	}
}
