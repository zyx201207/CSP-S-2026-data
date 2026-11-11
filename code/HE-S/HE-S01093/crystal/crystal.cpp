#include<bits/stdc++.h>
using namespace std;
int n,a[500001];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		sort(a+1,a+n+1);
		if(a[i]==a[n]&&i!=n){
		cout << m;
		return 0;
		}
		if(m==0) cout << "1";
		if(a[i+1]-a[i]==a[i+2]-a[i+1]&&a[i+1]-a[i]!=0){
			if(a[i+1]-a[i]>m){
			cout << "1"; return 0;
			}else if(a[i+1]-a[i]==m){
				cout << "2"; return 0;
			}
		}
	}
	int cnt=0,maxn=0,c=0,ans=0,d;
	for(int i =1;i<=n;i++){			
		int ans=a[1]+m;
		if(a[i]<=ans){
			c=c+a[i];
			ans++;
			int b=c/ans;
			while(n){
				d+=b-a[i];
				if(d==m){
				cnt++;
				}
			}
			maxn=max(maxn,cnt);
		}
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
