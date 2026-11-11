#include<bits/stdc++.h>
using namespace std;
long long n1;
long long n2;
long long n3;

char w;
int n;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>n;
		cin>>w;


		if(w=='a'){
			n1=n1+n;
			continue;

		}if(w=='b'){
			n2=n2+n;
			continue;

		}if(w=='c'){
			n3=n3+n;
			continue;

		}

	}
	long long maxn=max(n1,max(n2,n3));
	if((n1+n2+n3)%2==0){
		if(maxn>=(n1+n2+n3)/2){
			cout<<n1+n2+n3-maxn;

		}else{
			cout<<maxn;

		}


	}else{
		if(maxn<=(n1+n2+n3)/2){
			cout<<maxn;

		}else if(maxn>(n1+n2+n3)/2){
			cout<<n1+n2+n3-maxn;

		}
	}

	return 0;
}
