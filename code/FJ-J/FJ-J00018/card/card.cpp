#include <bits/stdc++.h>
using namespace std;

int check(long long *p,long long num,long long end){
	for (int i=0;i<end;i++){
		if (*(p+i) == num) return i+1;
	}
	return 0;
}

int main(){
	long long n,m;
	cin>>n>>m;
	long long card[n],pushed[m],ans[m];
	for (int i=0;i<n;i++){
		cin>>card[i];
	} 
	
	long long p=0;
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			if (p==0){
				pushed[p]=card[j];
				p++;
			}
			else if (check(&pushed[0],card[i],p)==0){
				pushed[p]=card[j];
			}
			else{
				p=check(&pushed[0],card[i],p)-1;
				pushed[p]=card[j]; 
			}
		}
		for (int j=0;i<p;j++){
			ans[pushed[j]]++;
		}
	}
	
	for (int i=0;i<m;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
