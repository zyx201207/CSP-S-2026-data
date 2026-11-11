#include<bits/stdc++.h>
using namespace std;
int a,t,cnt = 0;
char c,s[100001];
int n;
int sum = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a>>c;
		for(int j = 1;j<=a;j++){
			sum++;
			s[sum] = c;
		}
	}
	t = sum;
	sum-=1;
	sum/=2;
	t-=sum;
	t+=1;
	for(int i = 1;i<=sum;i++){
		if(s[i] != s[t]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
