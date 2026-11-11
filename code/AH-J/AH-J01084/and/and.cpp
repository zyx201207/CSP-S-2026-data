#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],c,u=1,ma,o,mi;
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			c=a[i];
		}else{
			c=c&a[i];
		}
		mi=max(mi,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			u++;
		}else{
			if(ma>=m){
				if(o<a[i-1]){
					o=a[i-1];
				}
			}else{
				ma=max(u,ma);
				o=a[i-1];
			}
		}
	}
	ma=max(u,ma);
	if(m==n){
		cout<<c;
	}else if(m==1){
		cout<<mi;
	}else if(m==2){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int q=a[i]&a[j];
				ma=max(ma,q);
			}
		}
	}else if(m==n-1){
		cout<<0;
	}else{
		if(ma>=m){
			cout<<o;
		}else{
			cout<<0;
		}
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
	return 0;
}
