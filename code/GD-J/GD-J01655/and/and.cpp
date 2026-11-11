#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx;
void work1(){
	int mx=0;
	for(int i=1;i<(1<<n);i++){
		int cnt=0,sum=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				cnt++;
				if(sum==0)sum=a[j];
				else sum=sum&a[j];
			}
		}
		if(cnt==m)mx=max(mx,sum);
	}
	cout<<mx;
}
void work2(){
	int mx=0;
	for(int i=1;i<=n;i++)mx=max(mx,a[i]);
	cout<<mx;
}
void work3(){
	int s=a[1];
	for(int i=2;i<=n;i++)s=s&a[i];
	cout<<s;
}
void work4(){
	int mx=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mx=max(mx,a[i]&a[j]);
		}
	}
	cout<<mx;
}
void work5(){
	int s=a[1],mx=0;
	for(int i=2;i<=n;i++)s=s&a[i];
	for(int i=1;i<=n;i++)mx=max(mx,s|a[i]);
	cout<<mx;
}
void work6(){
	sort(a+1,a+n+1,greater<int>());
	int s=a[1];
	for(int i=2;i<=m;i++)s=s&a[i];
	cout<<s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n<=20)work1();
	else if(n<=2000){
		if(m==1)work2();
		else if(m==n)work3();
		else if(m==2)work4();
	}
	else{
		if(m==n-1)work5();
		else work6();
	}
	return 0;
}
