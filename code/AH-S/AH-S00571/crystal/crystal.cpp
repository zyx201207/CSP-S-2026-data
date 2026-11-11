#include<bits/stdc++.h>
using namespace std;
const long long N=500010;
long long n,m,s,sum,sum2;
vector<long long> a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;;
	int dex=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	long long mid2=0;
	for(int i=0;i<a.size();i++){
		mid2=a[i];
		if(i!=0){
			s+=(i-dex)*(mid2-a[i-1]);
		}
		if(s>m){
			sum2=max(sum,sum2);
			while(s>m){
				sum--;
				s-=(mid2-a[dex]);
				dex++;
			}
			continue;
		}
		sum++;
	}
	cout<<sum2;
	return 0;
}
