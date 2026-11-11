#include<bits/stdc++.h>
using namespace std;

long long awy(long long a,long long b){
	vector<int> ai,bi;
	while(1){
		if(a/2==0){
			break;
		}
		ai.push_back(a%2);
		a/=2;
	}
	while(1){
		if(b/2==0){
			break;
		}
		bi.push_back(a%2);
		b/=2;
	}
	long long x=0;
	for(int i=min(a,b)-1;i>=0;i--){
		if(ai[i] && bi[i]){
			x++;
		}
	}
	return x;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long m,n;
	vector<long long> a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	long long x=a.size()-1;
	for(long long i=a.size()-2;i>=a.size()-(m+1);i--){
		x=awy(x,a[i]);
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
