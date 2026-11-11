#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<long long,char>> s;
	long long ssize=0;//记录字符串总长 
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		ssize+=a; 
		s.push_back({a,c});
	}
	long long need=ssize/2LL;//只需要向下取整 ,需要检测的数
	long long ip=0,ip2=n-1;//指针 
	pair<long long,char> a=s[ip];
	pair<long long,char> b=s[ip2];
	long long ans=0;//存储答案 
	while(need>0){
		long long diff=min(a.first,b.first);
		if(a.second!=b.second){//相等情况不需要检测 
			ans+=diff;
		}
		need-=diff;
		a.first-=diff;
		b.first-=diff;
		
		if(a.first==0){
			ip++;
			a=s[ip];
		}
		if(b.first==0){
			ip2--;
			b=s[ip2];
		}
		if(ip==ip2){
			break;
		}
		
		
	} 
	cout<<ans;
	cout<<flush;
	return 0; 
}
