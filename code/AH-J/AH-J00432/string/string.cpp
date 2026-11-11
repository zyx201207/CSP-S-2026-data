#include<bits/stdc++.h>
using namespace std;
long long a[300005];
string t,s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,num=0,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
		long long x;
		char y;
		cin>>x>>y;
		s[i]=y;
		a[i]=x;
		num+=a[i];
	}
	int cs=0,cd=0,bd=0,bs=n-1;
	for(int i=0;i<num/2;i++){
		   string l,r;
		   l=s[cd];
		   r=s[bs];
		   if(l[0]!=r[0]){
			   sum++;
		   }
		   cs++;
		   bd++;
		   if(cs==a[cd]){
			cd++;
			cs=0;   
		   }
		   if(bd==a[bs]){
			bs--;
			bd=0;   
		   }
	}
	cout<<sum;
}
