#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
string s[N];
long long z=1;
string wys(int n){
	string s1="";
	long long z1=z;
	int f=0;
	while(n!=0){
		
		if(n>=z1){
			s1+='1';
			n-=z1;
			f=1;
		} else{
			z1/=2;
			if(f==1){
				continue;
				f=0;
			}
			s1+='0';
		}
		
	} 
	while(z1!=1){
		z1/=2;
		s1+='0'; 
	}
	return s1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=5;i++){
		z*=2;
	} 	
	int n,m;
	cin>>n>>m;
	int mx1=0;
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
		mx1=max(mx1,a[i]);
		string s[i]=wys(a[i]);
	}
	if(m==1){
		cout<<mx1;
		return 0;
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		int sss=0;
		int k=0;
		for(int j=i+1;j<=n;j++){
			if(s[i]==s[j]){
				sss+=a[i]; 
				k++;
			}
			if(k>=m-1){
				break;
			} 
		}
		mx=max(mx,sss);
	}
	cout<<mx;
	return 0;
}
