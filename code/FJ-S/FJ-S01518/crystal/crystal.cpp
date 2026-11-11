#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],d[500010],s[500010],ans,ds[500010],dss[500010],o;
bool fa=1,fb=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)fa=0;
		if(i!=1&&i!=2&&a[i]-a[i-1]!=o)fb=0;
		else if(i==2)o=a[2]-a[1];
	}
	//dss[0]=1;
	sort(a+1,a+n+1);
	if(fa){
		for(int i=1;i<=n;i++){
			if(i*(i-1)/2<=m)ans=i;
			else break;
		}
		cout <<ans;
		return 0;
	}
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
		//ds[i]=ds[i-1]+d[i];
		//dss[i]=dss[i-1]+ds[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+d[i]*i;
	}
	if(fb){
		for(int i=1;i<=n;i++){
			if(s[i]<=m)ans=i;
			else break;
		}
		cout <<ans;
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(s[i-1]<=m){
			ans=max(ans,(ll)i);
			break;
		}
		else{
			ll ss=s[i-1];
			for(int j=1;j<i;j++){
				//if(i-j<=ans)break;
				ss-=(a[i]-a[j]);
				if(ss<=m){
					ans=max(ans,(ll)i-j);
					break;
				}
			}
		}
	}
	cout <<ans;
	return 0;
}



/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
