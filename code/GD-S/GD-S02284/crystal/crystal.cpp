#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=1,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	if(n%2==0){
		c=n/2;
	}else{
		c=n/2+1;
	}
	if(b[c]<b[c+1]){
		m-b[c];
		cnt++; 
	}
	if(b[c+1]==0){
		cnt++;
		m-b[c];
		cnt++;
	}
	if(m-(b[c]+b[c-1])>=0){
		m-=(b[c]+b[c-1]);
		cnt++;
	}
	else if(m-=(b[c]+b[c-1]+b[c-2])>=0){
		m-=(b[c]+b[c-1]+b[c-2]);
		cnt++;
	}
	else if(m-=(b[c]+b[c-1]+b[c-2]+b[c-3])>=0){
		m-=(b[c]+b[c-1]+b[c-2]+b[c-3]);
		cnt++;
	}
	else if(m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4])>=0){
		m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]);
		cnt++;
	}
	else if(m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5])>=0){
		m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5]);
		cnt++;
	}
	else if(m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5]+b[c-6])>=0){
		m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5]+b[c-6]);
		cnt++;
	}
	else if(m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5]+b[c-6]+b[c-7])>=0){
		m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5]+b[c-6]+b[c-7]);
		cnt++;
	}
	else if(m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5]+b[c-6]+b[c-7]+b[c-8])>=0){
		m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5]+b[c-6]+b[c-7]+b[c-8]);
		cnt++;
	}
	else if(m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5]+b[c-6]+b[c-7]+b[c-8]+b[c-9])>=0){
		m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5]+b[c-6]+b[c-7]+b[c-8]+b[c-9]);
		cnt++;
	}
	else if(m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5]+b[c-6]+b[c-7]+b[c-8]+b[c-9]+b[c-10])>=0){
		m-=(b[c]+b[c-1]+b[c-2]+b[c-3]+b[c-4]+b[c-5]+b[c-6]+b[c-7]+b[c-8]+b[c-9]+b[c-10]);
		cnt++;
	}
	cout<<cnt; 
	return 0;
} 
