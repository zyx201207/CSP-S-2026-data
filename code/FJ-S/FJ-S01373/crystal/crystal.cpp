#include <bits/stdc++.h> 
using namespace std;
long long n,m,ans,cj,tmp;
int a[500005];
priority_queue<long long,vector<long long>,greater<long long>> b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n >>m;
	for (long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for (long long i=1;i<n;i++){
		b.push(a[i]-a[i-1]);
	}
	for(long long i=0;i<n;i++){
		if(cj>m){
			if (tmp==1){
				break;
			}
			ans--;
			break;
		}
		else if(cj==m){
			break;
		}
		if (b.top()==0) {
			ans++;
			b.pop();
			tmp=1;
			continue;
		}
		cj+=b.top();
		b.pop();
		ans++;
	}
	cout <<ans;
	return 0;
}
