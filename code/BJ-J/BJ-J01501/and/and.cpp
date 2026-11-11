#include<bits/stdc++.h>
using namespace std;
long long lmax(long long a,long long b){
	if(a>=b)return a;
	else return b;
}
long long lmin(long long a,long long b){
	if(a>=b)return b;
	else return a;
}
bool cmp(int a,int b){
	return a>b;
}
int f(long long a,long long b[]){
	int n=0;
	while(b[n]>=pow(2,a))n++;
	return n-1;
}
int l(long long a){
	int i=0;
	while(pow(2,i)<=a)i++;
	return i-1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,mm=-1,ans=0;
	cin>>n>>m;
	long long num[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
		mm=lmax(mm,(int)l(num[i]));
		//cout<<(int)l(num[i]);
	}
	while(mm>=0){
	m=lmin(m,n);
	sort(num,num+n,cmp);
	if(num[m-1]>=int(pow(2,mm))){
		ans+=pow(2,mm);
		n=lmin(n,f(mm,num));
		//cout<<num[m-1]<<endl;
	}
	for(int i=0;i<n;i++)num[i]%=int(pow(2,mm));
	mm--;
	
	}
	cout<<ans;
	return 0;
	
}
