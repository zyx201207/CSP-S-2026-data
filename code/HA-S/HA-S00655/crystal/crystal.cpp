#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,cnt=0,sum=0,popCnt=0;
	float ave;
	cin>>n>>m;
	vector<long long>a(n);
	for(long long i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	ave=sum/n;
	sort(a.begin(),a.end());
	for(long long i=n-1;i>=0;i--){
		if(a[i]>ave){
			a.pop_back();
			popCnt++;
		}
	}
	int l=a.size();
	int k=l-l/2;
	for(int i=0;i<l;i++){
		m-=a[l];
		if(i==popCnt||m==0) break;
	}
	for(int i=0;i<l;i++) cnt++;
	cout<<cnt;
	return 0;
}
