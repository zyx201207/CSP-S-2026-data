#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010];
string b[400010];
int s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool p=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4) p=0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			s=max(s,a[i]);
		}
		cout<<s<<endl;
		return 0;
	}
	if(m==n){
		s=a[1];
		for(int i=2;i<=n;i++){
			s=s&a[i];
		}
		cout<<s<<endl;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				s=max(s,a[i]&a[j]);
			}
		}
		cout<<s<<endl;
		return 0;
	} 
	if(p){
		int e=0,b=0,c=0,d=0;
		for(int i=1;i<=n;i++){
			if(a[i]==4) d++;
			if(a[i]==3) c++;
			if(a[i]==2) b++;
			if(a[i]==1) e++;
		}
		if(m<=d){
			cout<<4<<endl;
			return 0;
		}
		if(m<=c){
			cout<<3<<endl;
			return 0;
		}
		if(m<=b+c){
			cout<<2<<endl;
			return 0;
		}
		if(m<=e+c){
			cout<<1<<endl;
			return 0;
		}
		cout<<0<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	s=a[n];
	for(int i=n-1;i>n-m;i--){
		s=s&a[i];
	}
	cout<<s<<endl;
	return 0;
} 
