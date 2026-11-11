#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
    long long m;
    cin>>n>>m;
    int w=0;
    long long num=0;
    long long a[100000];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long o=n/2;
	for(long long i=0;i<o;i++){
		a[i]+=a[o];
	}
	for(long long i=0;i<n;i++){
		if(a[i]=a[i+1]){
			num+=1; 
		}
}
	cout<<num;
	return 0;
}
