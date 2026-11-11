#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 5*1e5+5;
long long a[MAXN];
long long ds[MAXN];
map< long long,int > mp;
int n,ans=1;
long long m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	//记得删除批注！！！删除其余文件！！！ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(m>=1e9){
		long long d=a[2]-a[1];
		long long len=2*m/d;
		len=sqrt(len);
		long long m2=len*(len+1)*d;
		if(m2==(2*m)){
			cout<<len+1;
		}else{
			cout<<len;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	long long lin=0;
	for(int i=1;i<=n;i++){
		lin=a[i]-a[i-1];
		ds[i]=ds[i-1]+1LL*lin*(i-1);//需测试  
		//if(mp.find(ds[i])==mp.end()){
			//mp[ds[i]]=i;
		//} 
		if(ds[i]<=m){
			ans=max(ans,i);
			//cout<<i<<endl;
		}
	}
	//考虑要不要修改或者删除 
	//>ans 
	for(int i=ans+1;i<=n;i++){
		if(ds[i]<=m)continue;
		long long tem=ds[i]-m;
		int j=1;
		while(j<i){
			if((long long)(ds[j]+(a[i]-a[j])*j)>=tem){
				ans=max(ans,i-j);
				break;
			}
			j++;
		}
	}
	cout<<ans; 
	
	
	return 0;
} 
