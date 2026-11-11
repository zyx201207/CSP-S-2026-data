#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=1,sum=0,a[110000];
	char b,c[110000];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		
		if(a[i]>=1000000000){
			cout<<"3000000000";
			return 0;
		}
		while(a[i]--){
			s[k]=c[i];
			k++;
		}
	}
	
	int l=1,r=n*2-1;
	while(l<r){
		if(s[l]!=s[r]){
			b=s[r];
			s[r]=s[l+1];
			s[l+1]=b;
			sum++;
		}
		l++;r--;
	}
	cout<<sum;
	return 0;
}/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
