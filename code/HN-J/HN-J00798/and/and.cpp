//Trick||Treat!
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],t,num=1,cnt,t1,t2,maxx,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t=a[i];
		num=1;
		while(t){
			a[i]+=(t%2)*num;
			t/=2;
			num*=10;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			num=1;
			t1=a[i];
			t2=a[j];
			while(t1||t2){
				if(a[i]%10==1&&a[j]%10==1){
					cnt+=num*1;
				}
				num*=10;
				t1/=10;
				t2/=10;
			}
			maxx=max(maxx,cnt);
		}
	}
	num=1;
	while(maxx){
		ans+=(maxx%10)*num;
		maxx/=10;
		num*=10;
	}
	cout<<ans;
	
	return 0;
}
