#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	long long a,b;
	cin>>a>>b;
	vector<long long> s(a);
	for(long long i=1;i<=a;i++){
		cin>>s[i-1];
	} 
	sort(s.begin(),s.end());
	int f=1;
	int sum=s[1]-s[0];
	for(long long i=1;i<a;i++){
		if(s[i]-s[i-1]!=sum){
			f=0;
			break;
		}
	}
	if(f==1){
		int i;
		for(i=1;i<a;i++){
			if(b<sum*i){
				break;
			}
			b-=sum*i;
			 
		}
		cout<<i<<endl;
		return 0;
		
	}
	long long num=1;
	for(long long i=1;i<a;i++){
		long long ans=0;
		long long q=b;
		long long m=s[i];
		vector<long long> v;
		
		//向v中添加不大于v的数-----------------------------------------
		for(long long i=0;i<a;i++){ 
			if(s[i]<=m){
				v.push_back(s[i]);
			} 
			else{
				break;
			}
		}	
		
		
		//求局部最多大水晶数量-----------------------------------------
		for(long long j=0;j<v.size();j++){
			if(q<abs(m-v[j])){
				
				break;
			}
			else{
				q-=abs(m-v[j]);
				ans++;
			}
		}
		
		//判断全局最多水晶数量----------------------------------------- 
		if(ans>=num){
			num=ans;
		}
	} 
	cout<<num;
	return 0;
} 
