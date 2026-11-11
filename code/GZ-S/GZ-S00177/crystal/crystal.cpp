//GZ-S00177 华东师范大学附属贵阳学校 杨昊宸
//尝试二分答案 
//寻找多个数，加起来不超过m，使相同的数最多。所以二分答案是错的 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int N=5e5+3;
ll a[N];
ll num=INT_MIN,ans;
bool check(ll z){
	//queue<int> q,q2;
	//测试代码
	//cout<<"检查"<<z<<'\n'; 
	ll cost=0,cnt=0;
	for(int i=1;i<=n;++i){
		if(z>a[i]){
			cost+=z-a[i];
			cnt+=1;
			//q.push(i);
		}
		if(cost>m){
			//测试代码
			//cout<<"结果大了"<<'\n'<<"==========="<<'\n'; 
			//q=q2;
			return true;
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i]==z) cnt+=1;
	}
//	while(!q.empty()){
//		a[q.front()]=z;
//		q.pop();
//	}
	if(cnt>num){
		num=cnt;
		//m-=n*cnt;
	}
	//测试代码
	//cout<<"结果符合操作，花费："<<cost<<"合并数量"<<num<<'\n'<<"==========="<<'\n'; 
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	ll l=INT_MAX,r=INT_MIN;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		l=min(a[i],l);
		r=max(a[i],r);
	}
	int mid=0;
	//while(m>0){
		while(l<=r){
			//cout<<"边界："<<l<<' '<<r<<'\n';
			mid=(r-l)/2+l;
			if(check(mid)){//true表示大了和正好等于 
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		//ans+=num;
		//测试代码 
		//cout<<mid<<'\n';
	//}
	//cout<<ans;
	cout<<num;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
