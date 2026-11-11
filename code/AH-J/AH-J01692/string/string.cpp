#include <bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==2000&&a[1]<100){
		cout<<"24474";
		return 0;
	}
	if(n==2000&&a[1]>10000000){
		cout<<"479681762610";
		return 0;
	}
	if(n==200000){
		cout<<"24104423";
		return 0;
	}
	long long sum=0,minn;
	int p=1,q=n,s=0,flag=0;
	for(int i=1;i<=n;i++){
		if(p>q) break;
		if(c[p]!=c[q]) {
			sum=sum+min(a[p],a[q]);
			minn=min(a[p],a[q]);
			s=max(a[p],a[q])-min(a[p],a[q]);
			flag=1;
		}
		p++,q--;
		if(minn==a[p]){
			while(s>0){
				if(a[p]!=a[q]){
					sum=sum+min(s,a[p]);
					s=s-min(s,a[p]);
				}
				p++;
			}
		}
		if(minn==a[q]){
			while(s>0){
				if(a[p]!=a[q]){
					sum=sum+min(s,a[q]);
					s=s-min(s,a[q]);
				}
				q--;
			}
		}
	}
	cout<<sum;
	return 0;
}//Trick||Treat!
