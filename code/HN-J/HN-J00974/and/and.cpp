#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

#define int long long
int n,m,a[N],b[N];
queue<int> que;
int t[40];
string s[N];
//un
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	
	cin>>n>>m;
	m=n-m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],l=0;
		for(int k=30;k>=0;k--){
			int v=pow(2,k);
			if(x>=v) x-=v;
			else t[k]++;
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int k=30;k>=0;k--){
		if(t[k]>m) continue;
		for(int i=1;i<=n;i++){
			int v=pow(2,k);
			if(b[i]>=v){
				b[i]-=v;
			}else{
				m--;
				que.push(i);
			}
		}
	}

	
	
	
	int sum=pow(2,31)-1;
	for(int i=1;i<=n;i++){
		if(i!=que.front()){
			sum &= a[i];
		}else que.pop();
	}
	cout<<sum;
	return 0;
}

