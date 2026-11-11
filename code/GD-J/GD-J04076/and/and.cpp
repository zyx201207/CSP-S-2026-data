#include<bits/stdc++.h>
using namespace std;
long long q[200010];
int a(int n,long long q[200010],int m){
	int max=0;
	int s[200010];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(max<(q[i]&q[j])){
				max=(q[i]&q[j]);
				s[i]=max;
			}
		}
	}
	for(int i=1;i<=n;i++){
		q[i]=s[i];
	}
	if(m!=1){
		m-=1;
		a(n,q,m);
	}
	else{
		cout <<max;
	}
	return 0;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n=0,m=0;
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>q[i];
	}
	cout <<q[n];
	return 0;
} 
