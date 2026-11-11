#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005],minn=10000000;
int chaz(int x,int nn){
	int sum=0;
	for(int i=1;i<=nn;i++){
		if(a[i]>x){
			sum+=a[i]-x;
		}
		else
			sum+=x-a[i];
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,anss,mmxx,num;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		mmxx=chaz(a[i],n);
		if(mmxx<minn){
			minn=mmxx;
			num=a[i];
		} 
	}
	for(int i=1;i<=n;i++){
		if(a[i]>num){
			c[i]=a[i]-num;
		}
		else{
			c[i]=num-a[i];
		}
	}
	num=0;
	int i=1;
	sort(c+1,c+n+1);
	cout<<endl;
	while(num<m){
		if(num+c[i]>m){
			break;
		}
		else{
			num+=c[i];
			anss++;
		}
		i++;
		if(i>n){
			break;
		}
	}
	cout<<anss;
	
	return 0;
} 
