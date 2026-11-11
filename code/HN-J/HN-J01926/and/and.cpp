#include<bits/stdc++.h>
using namespace std;
bool vis[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200010],maax=-1,ans=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>maax) maax=a[i];
	}
	long long cnt=1;
	bool f=0;
	while(cnt<maax){
		cnt*=2;
	}
	cnt/=2;
	for(int i=cnt;i>=1;i/=2){
		long long num=0;
		vector <int> s;
		for(int j=1;j<=n;j++){
			if((a[j]&i)==i) num++;
			else{
				if(vis[j]!=1){
					s.push_back(j);
					vis[j]=1;
				}
			}
		}
		if(num>=m){
			ans+=i;
			for(int j=0;j<s.size();j++){
				a[s[j]]=0;
			}
		}
	}
	cout << ans;
	return 0;
}
