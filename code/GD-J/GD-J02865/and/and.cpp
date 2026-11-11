#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a>b;
}

bool two(int n){
	bool flag=true;
	if(n==1||n==0)return 0;
	while(n!=1){
		if(n%2!=0){
			flag=false;
			return flag;
		}
		n/=2;
	}
	return flag;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	queue <int> q;
	int n, m, cnt=0;
	cin>>n>>m;
	int a[n];
	for(int i=0; i<n; i++)cin>>a[i];
	sort(a, a+n, cmp);
	for(int i=0; i<n-m; i++){
		q.push(a[i]);
		for(int j=i+1; j<n; j++){
			if(a[i]%a[j]==0){
				if(!two(a[i]/a[j]) && cnt<m){
					q.push(a[j]);
					cnt++;
				}
			}
			else if(cnt<m){
				q.push(a[j]);
				cnt++;
			}
		}
		if(q.size()<m){
			for(int i=0; i<q.size(); i++){
				q.pop();
			}
		}
	}
	int sum=q.front();
	for(int i=0; i<q.size(); i++){
		sum=sum&q.front();
		q.pop();
	}
	cout<<sum;
	return 0;
} 
