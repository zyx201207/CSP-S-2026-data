#include<bits/stdc++.h>
using namespace std;
struct o{
	long long n;
	char ch;
}a[200005];
unsigned long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
		cin>>a[i].n>>a[i].ch;
	}
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=i-1;j--){
			if(a[i].n>=a[j].n && a[i].ch!=a[j].ch){
				a[i].n-=a[j].n;
				ans+=a[j].n;
				n--;
				if(a[i].n==0) break;
			}else if(a[i].ch==a[j].ch){
				a[i].n-=a[j].n;
				n--;
			}else{
				a[j].n-=a[i].n;
				ans+=a[i].n;
				break;
			}
		}
	}
	cout<<ans;
}
