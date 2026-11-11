#include<bits/stdc++.h>
using namespace std;

queue <int> s;
int a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,x;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>x;
		while(x != 0){
			s.push(x%2);
			x/=2;
		}
		int t=s.size();
		for (int j=1;j<=t;j++){
			a[j]+=s.front();
			s.pop();
		}
	}
	int sum=0,num=0;
	for (int i=n;i>=1;i--){
		if (num == m){
			cout<<sum;
			return 0;
		}
		if (a[i] >= m){
			num++;
			sum+=1<<(i-1);
		}
	}
	cout<<sum;
	return 0;
} 
