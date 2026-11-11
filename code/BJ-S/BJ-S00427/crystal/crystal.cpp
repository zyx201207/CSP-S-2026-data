#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

int n,m;
int a[500005];
int b[500005];
int v[500005];
int ma=0;
//vector<int> v;

bool cmp(int x,int y){
	return x>y;
}

//long long use(int x){
//	for(int i = x-1;i>=1;i--){
//		if(b[i]!=0){
//			;
//		}
//	}
//}
int ans=0;
bool flagA=1;
bool flagB=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	memset(b,0,sizeof(b));
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flagA=0;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])flagB=0;
		//b[a[i]]++;
		//ma=max(a[i],ma);
	}
	
	if(flagA){
		ans=1;
		for(int i = 1;i<=1000000000;i++){
			if(i<=m){
				ans++;
				m-=i;
				//cout<<i<<" ";
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	
	if(flagB){
		ans=1;
		int cha=a[2]-a[1];
		for(int i = 1;i<=1000000000;i+=cha){
			if(i<=m){
				ans++;
				m-=i;
				//cout<<i<<" ";
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i<=n;i++){//bao li
		int mm=m;
		int sum=1;
		for(int j = i+1;j<=n;j++){
			if(a[i]-a[j]<=mm){
				mm-=a[i]-a[j];
				sum++;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
