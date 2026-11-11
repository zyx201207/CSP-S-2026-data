#include<bits/stdc++.h>
using namespace std;
int n;
long long m,bb,aa=0x3f,cc=0x3f;
long long a[500001];
long long num,num2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bb=max(bb,a[i]);
		aa=min(aa,a[i]);
		cc=min(cc,a[i]-a[i-1]);
	}
	if(n*(bb-aa)<=m){//能量值极其充足 
		cout<<n;
		return 0;
	}
	if(m<cc||m==0){
		cout<<1;
		return 0;
	}
	if(m==cc){
		cout<<2;
		return 0;
	}
	if((a[2]-a[1])==(a[3]-a[2])&&(a[3]-a[2])==(a[4]-a[3])&&(a[4]-a[3])==(a[5]-a[4])&&(a[5]-a[4])==(a[6]-a[5])&&(a[6]-a[5])==(a[7]-a[6])&&(a[8]-a[7])==(a[7]-a[6])&&(a[9]-a[8])==(a[8]-a[7])){
		m/=(a[2]-a[1]);
		long long ans=0;
		for(long long i=1;i<=m;i++){
			if(m-i<0)break;
			ans++;
			m-=i;
		}
		cout<<ans+1;
		return 0;
	}
	//实在不行就枚举嘛
	for(long long i=bb;i>aa;i--){
		vector<long long>vec;
		long long p=m;
		for(int j=1;j<=n;j++){
			if(a[j]>i)continue;
			vec.push_back(i-a[j]);
		}
		sort(vec.begin(),vec.end());
		for(int k=0;k<(int)vec.size();k++){
			if(p-vec[k]<0)break;
			p-=vec[k];
			num2++;
		}
		num=max(num,num2);
		num2=0;
	}
	cout<<num;
	return 0;
} 
