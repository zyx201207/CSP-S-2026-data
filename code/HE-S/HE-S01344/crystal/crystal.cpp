#include<bits/stdc++.h> 
using namespace std;
int a[10010],b[10010],c[10010];
int n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=0,s=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==1)k++;
	}
	int cnt=m;
	if(k=n-1){
		for(int i=1;i<=n;i++){
			cnt-=i;
			s++;
			if(cnt<i+1){
				cout<<s+1;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==n)break;
		b[i]=a[i+1]-a[i];
	}
	int sum=0;
	for(int i=1;i<n;i++){
		sum=0;
		int cnt1=b[i];
		cnt=m;
		while(cnt>=cnt1){
			cnt-=cnt1;
			cnt1+=b[i+1];
			sum++;
			i++;
		}
		i-=sum;
		c[i]=sum+1;
	}
	sort(c,c+n,greater<int>());
	cout<<c[1];
	return 0;
}
