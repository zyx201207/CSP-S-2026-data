#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
string s;
struct str{
	int m;
	char b;
}a[20000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].b;
		for(int j=k;j<k+a[i].m;j++){
			s[j]=a[i].b;
		}
		k+=a[i].m;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	int t=k/2;
	for(int i=0;i<t;i++){
		if(s[i]!=s[k-i-1]) sum++;
	}
	cout<<sum;
	return 0;
} 
