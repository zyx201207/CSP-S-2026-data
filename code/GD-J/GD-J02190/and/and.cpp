#include <bits/stdc++.h>
using namespace std;
/*string transtotwo(long long x){
	string s;
	long long i=0;
	while(x!=0){
		s[i]=x%2+'0';
		x/=2;
		i++;
	}
	i--;
	//for(long long k=0;k<=i;k++)
	//	cout<<s[k];
	string s1;
	long long j=0;
	while(i>=0){
		s1[j]=s[i];
		j++;
		i--;
	}
	return s1;
}
int joker(long long x,long long y){
	string s=transtotwo(x),s1=transtotwo(y);
	unsigned long long a=s.size(),b=s1.size(),c=max(a,b);
	string s2;
	
	return 0;
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	//for(long long i=1;i<=n;i++)
	//	cout<<a[i];
	//cout<<transtotwo(10);
	if(m==1)
		cout<<a[n];
}
