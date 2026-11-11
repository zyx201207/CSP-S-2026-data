#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans=0;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(m==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<n;i++){
		sum[i]=a[i+1]-a[i];
	}
	long long h=0;
	for(int i=1;i<n;i++){
		if(sum[i]==0){
			ans++;
			continue;
		}
		if(h+i*sum[i]>m){
			for(int j=1;j<=i;j++){
				if(h+sum[i]<=m){
					h+=sum[i];
					ans++;
				}
				break;
			}
			break;
		}
		h+=i*sum[i];
		ans+=i;
	}
	cout<<ans;
	return 0;
}
//Tigao group's questions are very hard for me.It made me spend 4 hours on sitting the exam point.
//"crystal" was only question for my doing and I didn't think of this is correct. 
//I think my grade don't more than 50.
//Though this,I always shut up "挽昼大人万岁!!!" again and again to cheer my mind...
