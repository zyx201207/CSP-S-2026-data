#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long t;
	char s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	bool f=true,F=true;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].s;
		a[0].t+=a[i].t;
		if(i>1&&f==true){
			if(a[i].s!=a[i-1].s){
				f=false;
			}
		}
		if(i>1&&F==true){
			if(a[i].t!=a[i-1].t){
				F=false;
			}
		}
	}
	if(f==true){
		cout<<sum;
		return 0;
	}
	if(F==true){
		for(int i=1;i<=n/2;i++){
			if(a[i].s!=a[n-i+1].s){
				sum++;
			}
		}
		cout<<sum*a[1].t;
		return 0;
	}
	string s=" ";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].t;j++){
			s+=a[i].s;
		}
	}
	for(int i=1;i<=a[0].t/2;i++){
		if(s[i]!=s[a[0].t-i+1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
