#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long o[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>o[i];
	}
	long long p=0;
	long long count=0;
	for(int i=0;i<n;i++){
		count+=o[i];
	}
	count/=n;
	long long qwe;
	for(int i=0;i<n;i++){
		while(m!=0){
			qwe=i;
			if(o[i]>count){
				o[i]--;
				m--;
			}
			if(o[i]<count){
				o[i]++;
				m--;
			}
			if(o[i]==count){
				p++;
				break;
			}		
		}
	}
	qwe+=1;
	for(int i=qwe;i<n;i++){
		if(o[i]==count){
			p++;
		}
	}
	cout<<p;
	return 0;
} 
