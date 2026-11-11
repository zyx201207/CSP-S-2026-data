#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,ans;
struct{
	long long a;
	char b;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
		long long a1;
		cin>>a1;
		char b1;
		cin>>b1;
		a[i].a=a1;
		a[i].b=b1;
	}
	int i=0,j=n-1;
	while(i<j){
		if(a[i].b!=a[j].b){
			if(a[i].a<a[j].a){
				ans+=a[i].a;
				a[j].a-=a[i].a;
				a[i].a=0;
				i++;
			}else if(a[i].a>a[j].a){
				ans+=a[j].a;
				a[i].a-=a[j].a;
				a[j].a=0;
				j--;
			}else{
				ans+=a[j].a;
				i++;
				j--;
			}
		}else{
			if(a[i].a>a[j].a){
				a[i].a-=a[j].a;
				j--;
			}else if(a[i].a<a[j].a){
				a[j].a-=a[i].a;
				i++;
			}else{
				i++;
				j--;
			}
		}
		if(i>=j){
			break;
		}
	}
	cout<<ans;
    return 0;
}
