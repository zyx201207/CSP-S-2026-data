#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	unsigned long long a[maxn];
	string c[maxn];
	unsigned long long ans=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	string *p=&c[1];
	string *q=&c[n];
	unsigned long long n1=a[1];
	unsigned long long m=a[n];
	int k=1;
	int j=1;
	while(p!=q&&p<=q){
		cout<<*p<<" "<<*q<<" "<<ans<<endl;
		if(*p==*q){
			if(m>n1){
				m-=n1;
				p++;
				n1=a[1+k];
				k++;
				continue;
			}
			if(m<n1){
				n-=m;
				q--;
				m=a[n-j];
				j++;
				continue;
			}
			if(m==n1){
				p++;
				n1=a[1+k];
				q--;
				m=a[n-j];
				k++;
				j++;
				continue;
			}
		} 
		else{
			ans+=min(n1,m);
			if(m>n1){
				m-=n1;
				p++;
				n=a[1+k];
				k++;
				continue;
			}
			if(m<n1){
				n1-=m;
				q--;
				m=a[n-j];
				j++;
				continue;
			}
			if(m==n1){
				p++;
				n1=a[1+k];
				q--;
				m=a[n-j];
				k++;
				j++;
				continue;
			}
		}
		
	}
	cout<<ans;
	return 0;
			
}
