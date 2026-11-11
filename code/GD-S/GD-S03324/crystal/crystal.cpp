#include<bits/stdc++.h>
using namespace std;
struct node{
	long long data;
	int same;
};
int n;
long long m,ans=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long>a(n);
	vector<long long>b(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	b[0]=0;
	for(int i=1;i<n;i++)b[i]=a[i]-a[i-1];
	for(int i=1;i<n;i++){
		if(b[i]>m)continue;
		long long ms=m;
		long long cnt=1;
		while(ms>=0&&i<n){
			if(ms==0&&b[i]!=0)break;
			if(ms>=b[i]){
				ms-=b[i];
				cnt++;
				i++;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
	//wo shi cai ji QAQ
}
