#include<bits/stdc++.h>
using namespace std;

long long n;
long long cnt;
long long num[10011],qz[10011];
string c;

char mb(int k){
	long long w=1;
	
	for(int i=1;i<=k;i++){
		if(i>qz[w]){
			w++;
		}
	}
	return c[w];
}


int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>num[i];
		cin>>c[i];
		qz[i]=num[i]+qz[i-1];
	}
	
	for(int i=1;i<=qz[n]/2;i++){
		
		if(mb(i)==mb(qz[n]-i+1)){
			
			continue;
		}
		cnt++;
	}
	
	cout<<cnt;
	return 0;
}
