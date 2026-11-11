#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;//n大小，数组长度
int ans;
long long n,m,pos,minn=1e12+5;
long long a[N],d[N];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
		if(d[i]<minn){
			pos=i;
			minn=d[i];
		}
	}
	while(m>0){
		if(m>=minn){
			a[pos]+=minn;
			d[pos]=1e12+5;
			m-=minn;
			ans++;
		}else break;
		for(int i=1;i<n;i++){
			if(d[i]<minn){
				pos=i;
				minn=d[i];
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
