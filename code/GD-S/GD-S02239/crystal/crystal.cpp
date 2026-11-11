#include<bits/stdc++.h>
using namespace std;
int a[500005]={0};
int check(int a[500005], int bg,int n,int m){
	int can=1;
	int now=1;
	int nowb=bg;
	for(;nowb<n;){
		if((a[nowb+1]-a[nowb])*now <= m){
			can++;
//			cout<<"YES"<<endl;
			m-=(a[nowb+1]-a[nowb]) * now;
			now++;
			nowb++;
		}
		else{
			break;
		}
	}
	return can;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 	
	long long n=0,m=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n-1;i++){
//		cout<<a[i]<<" "<<i<<" "<<ans<<endl;
		ans = max(ans, check(a,i,n,m));	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
