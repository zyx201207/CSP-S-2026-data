#include<bits/stdc++.h>
using namespace std;
long long n,m,a[210000],max1=0,ans;
void d(long long p,long long max2,long long now){
	if(p==0){
		return ;
	}
	for(int i=now;i<n;i++){
		ans=a[i]&a[i+1];
		max2=max(max2,ans);
		d(p-1,max2,now+1);
	}
	max1=max2;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	d(m,0,1);
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
