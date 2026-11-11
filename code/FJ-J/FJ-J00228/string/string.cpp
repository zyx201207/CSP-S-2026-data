#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	
	cin>>n;
	int x;
	long long k=1;
	char c;
	while(n!=0){
		n--;
		cin>>x;
		cin>>c;
		for(int i=1;i<=x;i++){
			a[k]=c;
			k++;
		}
	}long long num=0;
	for(int i=1;i<=k-1;i++){
		if(a[i]!=a[k-i]){
			num++;
		}
	}cout<<num/2;
	
	return 0;
} 
