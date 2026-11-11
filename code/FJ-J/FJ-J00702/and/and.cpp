#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long c[a+1];
	for(long long i=1;i<=a;i++){
		cin>>c[i];
	}
	for(long long i=1;i<=a;i++){
		for(long long j=i;j<=a;j++){
			if(c[j]>c[i]){
				swap(c[j],c[i]);
			}
		}
	}
	int s=0;
	for(long long i=2;i<=b;i++){
		s=c[i-1]&c[i];
	}
	cout<<s;
	return 0;
}
