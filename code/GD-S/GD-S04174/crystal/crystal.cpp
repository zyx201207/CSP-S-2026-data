#include<bits/stdc++.h>
using namespace std;

vector<long long> s;
vector<long long> a;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,mz,cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		a.push_back(b);
		}
	sort(a.begin(),a.end());
	mz=a[n/2];
	for(int i=0;i<n/2;i++){
		long long k=abs(a[i]-mz);
		s.push_back(k);
	}
	for(int i=n/2+1;i<n;i++){
		long long k=abs(a[i]-mz);
		s.push_back(k);
	}
	sort(s.begin(),s.end());
	for(int i=0;;i++){
		if(m<0) break;
		m-=s[i];
		cnt++;
	}
	cout<<cnt;
	return 0;
} 
