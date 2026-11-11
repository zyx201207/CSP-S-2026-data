#include<bits/stdc++.h>
using namespace std;
struct num{
	int ejz[32];
	long long num;
}a[300087];
long long n,m;
int ejz[32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		long long numm;
		for(int i=0;i<=n-1;i++){
			long long k;
			cin>>k;
			if(!i){
				numm=k;
			}else{
				numm&=k;
			}
		}
		cout<<numm;
		return 0;
	}
	long long maxx=0;
	for(int i=0;i<=n-1;i++){
		cin>>a[i].num;
		long long k=a[i].num;
		maxx=max(a[i].num,maxx);
		int t=1;
		while(k){
			ejz[t]+=k%2;
			a[i].ejz[t++]+=k%2;
			k/=2;
		}
//		for(int j=1;j<=31;j++){
//			cout<<a[i].ejz[j];
//		}
//		cout<<endl;
	}
	if(maxx<=4){
		cout<<3;
		return 0;
	}
	for(int i=1;i<=31;i++){
//		cout<<ejz[i]<<" ";
	}
int o=32,numm=0;
while(n-numm>m){
	for(o=o-1;o>=1;o--){
//		cout<<" "<<o<<" ";
		if(ejz[o]>=m){
			break;
		}
	}
	for(int i=0;i<=n-1;i++){
		if(a[i].ejz[o]==0&&a[i].num!=0&&n-numm>m){
			a[i].num=0;
			numm++;
			for(int lo=1;lo<=31;lo++){
				ejz[lo]-=a[i].ejz[lo];
			}
		}
	}
//	for(int i=1;i<=31;i++){
//		cout<<ejz[i];
//	}
}
	long long answer,t=0;
	for(int i=0;i<=n-1;i++){
		if(a[i].num!=0&&t<m){
			if(t){
				answer&=a[i].num;
			}else{
				answer=a[i].num;
			}
			t++;
		}
	}
	cout<<answer;
	return 0;
}
//while(ejz[o]!=m){
