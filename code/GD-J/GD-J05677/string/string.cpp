#include<bits/stdc++.h>
using namespace std;

long long n;
long long sum;
string s;
struct tmp{
	long long a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;	
	tmp a[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	 
	for(int i=1;i<=n/2;i++){
		long long x= n-i+1;
		if(a[i].c != a[x].c){
			if(a[i].a > a[x].a){
				sum+= a[x].a;
				a[i].a -= a[x].a;
				a[x].a = 0;
			}else if(a[x].a > a[i].a){
				sum+= a[i].a;
				a[x].a -= a[i].a;
				a[i].a = 0;
			}else {
				sum += a[i].a;
				a[i].a = a[x].a=0;
			} 
		}else{
			if(a[i].a > a[x].a){
				a[i].a -= a[x].a;
				a[x].a = 0;
			}else if(a[i].a < a[x].a){
				a[x].a -= a[i].a;
				a[i].a = 0;
			}else{
				a[i].a = a[x].a =0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].a != 0){
			for(int j= 0;j<a[i].a;j++) s+=a[i].c;
		}
	}
	for(int i=1;i<=s.size()/2;i++){
		long long x= n-i+1;
		if(s[i] !=s[x]){
			sum++;
		}
	}
    cout<<sum;
	return 0;
}
