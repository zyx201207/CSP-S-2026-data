#include<bits/stdc++.h>
using namespace std;
struct{
	long long a;
	string b;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,lo = 0,s = 0,w=0;
	cin>>n;
	for(long long i =1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
		lo+=a[i].a;
	}
	int l = 1,r = n;
	while(w<=lo/2&&l<=r){
		if(a[l].b!=a[r].b){
			if(a[l].a<a[r].a){
				s+=a[l].a;
				w+=a[l].a;
				a[r].a-=a[l].a;
				l++;
			}
			else if(a[l].a==a[r].a){
				s+=a[l].a;
				w+=a[l].a;
				l++;
				r--;
			}
			else{
				s+=a[r].a;
				w+=a[r].a;
				a[l].a-=a[r].a;
				r--;
			}
		}
		else{
			if(a[l].a<a[r].a){
				w+=a[l].a;
				a[r].a-=a[l].a;
				l++;
			}
			else if(a[l].a==a[r].a){
				w+=a[l].a;
				l++;
				r--;
			}
			else{
				w+=a[r].a;
				a[l].a-=a[r].a;
				r--;
			}
		}
	}
	cout<<s;
}
