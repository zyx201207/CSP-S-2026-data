#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);

	long long n;
	long long m;
	long long maxn=0;
	long long temp,s;
	int crystal[500005];
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>crystal[i];
	}
	sort(crystal,crystal+n);
	for(int i=1;i<n;i++){
		s=m;
		temp=0;
		
		while(s>0&&s<=m){
			s=s-crystal[i]+crystal[temp];
			temp++;
			if(s<=m){
			maxn=max(maxn,temp+1);
			maxn=min(maxn,n);	
			}
			
			cout<<maxn<<"   "<<temp<<"   "<<s<<endl;
			
		}
	}
	cout<<maxn;
	
	return 0;
} 
