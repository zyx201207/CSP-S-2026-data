#include<bits/stdc++.h> 
using namespace std;
bool cmp(long n,long m){
	return n<m;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//cout<<(31 &15 & 7 & 3);
	long long a,b,maxn=-1;
	cin>>a>>b;
	long long a1[a];
	for(long long i=1;i<=a;i++){
		cin>>a1[i];}

	if(a==b){
		cout<<0;
		return 0;
	}
	if(b==2){
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				if(a1[i] & a1[j]>=maxn){
					maxn=a1[i] & a1[j];
				}
			}
		}
	cout<<maxn<<endl;
	return 0;}
	sort(a1,a1+a+1,cmp);
	cout<<a1[b-1];
	return 0;
}
