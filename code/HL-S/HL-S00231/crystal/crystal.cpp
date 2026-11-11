#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    int a[100005]={0};
    int sum[100005]={0};
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	sum[i+1]=sum[i]+a[i];
	}
//	for(int i=0;i<n;i++){
//		if(a[i]<=m){
//			ans++;
//		}
//	}
    for(int i=0;i<n;i++){
    	int num=0;
    	num=i*a[i]-sum[i];
    	if(num<=m){
    		ans=i;
		}
	}
	cout<<ans+1;
//    fclose(stdin);
//    fclose(stdout);
	return 0;
}
