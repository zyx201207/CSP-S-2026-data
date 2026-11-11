#include<bits/stdc++.h>
using namespace std;
int n,m,maxsum,sums;
long long a[200005],num[50],maxn,sum;
int maxs,w=1,ok;
string str;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	string s[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]>maxn){
			maxn=a[i];
			w=i;
		}
		sum&=a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	sum=a[1];
	for(int i=2;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	return 0;
} 
