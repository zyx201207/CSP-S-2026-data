#include<bits/stdc++.h>
using namespace std;
const int M=200005;
long long a[M];
char b[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	int o=n;
	long long p=0;
	for(int i=1;i<=o;i+=0){
		if(i==o) break;
		if(a[i]==a[o]){
			if(b[i]==b[o]){
				o--;
				i++;
			}else{
				p+=a[i];
				o--;
				i++;
			}
		}else if(a[i]>a[o]){
			if(b[i]==b[o]){
				a[i]-=a[o];
				o--;
			}else{
				p+=a[o];
				a[i]-=a[o];
				o--;
			}
		}else{
			if(b[i]==b[o]){
				a[o]-=a[i];
				i++;
			}else{
				p+=a[i];
				a[o]-=a[i];
				i++;
			}
		}	
	}
	cout<<p;
}
