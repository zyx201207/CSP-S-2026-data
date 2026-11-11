#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int b[100001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,a[100001],s=1,s1,m1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];b[a[i]]++;
	}
	sort(a+1,a+1+n);
	if(n==1){
		cout<<"1";return 0;
	}
	if(m==0){
	s1=0;
	for(int i=1;i<=n;i++){
		if(b[a[i]]>s){
			s=b[a[i]];
		}
	}
	cout<<s;return 0;
	}
	else{
	for(int i=1;i<=n-1;i++){
	s1=1;m1=m;
	for(int o=i+1;o<=n;o++){
	if(m1-s1*(a[o]-a[o-1])>=0){
		m1=m1-s1*(a[o]-a[o-1]);
		s1++;
	}
	else{
		o=n+1;
	}	
	}
	if(s1>s){
		s=s1;
	}	
	}	
	cout<<s;
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
} 
