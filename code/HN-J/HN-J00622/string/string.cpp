#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,e=0;
	long long d=0;
	cin>>n;
	int a[n];
	char b[n];
	string c="";
	for(int q=0;q<n;q++){
		cin>>a[q];
		cin>>b[q];
	}
	for(int q=0,w=n-1;q<w;){
		if(b[q]==b[w]){
			int e=a[q]>a[w]?a[w]:a[q];
			a[q]-=e;
			a[w]-=e;
			if(a[q]==0){
				q++;
			}
			if(a[w]==0){
				w--;
			}
		}
		else{
			d+=a[q]>a[w]?a[w]:a[q];
			int e=a[q]>a[w]?a[w]:a[q];
			a[q]-=e;
			a[w]-=e;
			if(a[q]==0){
				q++;
			}
			if(a[w]==0){
				w--;
			}
		}
	}
	cout<<d;
	return 0;
} 
