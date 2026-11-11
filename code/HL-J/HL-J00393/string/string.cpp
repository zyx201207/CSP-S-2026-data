#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
char b[100000005];
char s[1000000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,l=1,r,n1=0,sum=0,s1=1;
	bool f=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[s1]=b[i];
			s1++;
		}
		n1+=a[i];
	}
	r=n1;
	for(int i=1;i<=n1/2;i++){
		if(s[l]!=s[r]){
			sum+=1;
		}
		l++;
		r--;
	}	
	cout<<sum;
	return 0;
}
