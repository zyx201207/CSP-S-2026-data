#include<bits/stdc++.h>
using namespace std;
map<long long,long long> num;
long long n,m,t,ans;
bool flag=true;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>t;
		num[t]++;
	}t=0;
	m=n-m+1;
	for(auto o:num){
		t+=o.second;
		if(m<=t){	
			if(m==t){
				ans=o.first;
				flag=false;
			}else if(flag){
				ans=o.first;
				o.second=t-m+1;
				flag=false;
			}
			for(int i=0;i<o.second;i++){
				ans=ans&o.first;
			}
		}
	}cout<<ans;
	return 0;
}

