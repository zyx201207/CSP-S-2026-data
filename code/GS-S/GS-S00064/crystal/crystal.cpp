#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
vector<long long>a;
vector<long long>w;
vector<long long>s;

long long ans = 0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	a.push_back(0);
	w.push_back(0);
	s.push_back(0);
	
	//输入处理 
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		int ai = 0;
		cin>>ai;
		a.push_back(ai);
	}
	sort(a.begin()+1,a.begin()+n+2);
	
	//前缀和 
	for(int i = 1;i<=n;i++){
		long long wi = w[i-1]+(i-1)*(a[i]-a[i-1]);
		w.push_back(wi);
	}
	for(int i = 1;i<=n;i++){
		long long si = s[i-1]+a[i];
		s.push_back(si);
	}
	
	//A\B性质 
	int flag1 = true;
	int cha = a[3]-a[2];
	for(int i = 3;i<=n;i++){
		if(!(cha == a[i]-a[i-1])){
			flag1 = false;
			break;
		}
	}
	if(flag1){
		int i = 1;
		for(;i<=n;i++){
			if(w[i]>m)break;
		}
		cout<<i-1;
		return 0;
	}
	
	//dfs
	for(int i = 1;i<=n;i++){
		for(int j = i-1;j>=1;j--){
			long long wi = a[i]*(i-j+1) - (s[i]-s[j-1]);
			long long len = i-j+1;
			if(wi > m){
				ans = max(ans,len-1);
				break;
			}else{
				ans = max(ans,len);
			}
		}
	}
	
	cout<<ans;
	return 0;
}
