#include<bits/stdc++.h>
using namespace std;
long long num[500005],e[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);
	
	e[0]=0;
	long long me=0,nowm;
	for(int i=1;i<n;i++){
		nowm=m;
		for(int j=i-1;j>=0;j--){
			if(num[i]-num[j]<=nowm){
				nowm-=num[i]-num[j];
				e[i]++;
			}
			else break;
		}
		if(e[i]>me)me=e[i];
	}
	cout<<me+1;
	
	return 0;
} 
