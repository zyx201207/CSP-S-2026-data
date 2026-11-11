#include<bits/stdc++.h>
using namespace std;
long long n,z,ans=0,ss,d;
int w=1;
struct aa{
	long long s;
	char c;
	int id;
}a[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0].id=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		cin>>a[i].c;
		ss=ss+a[i].s;
		a[i].id=a[i-1].id+a[i].s;
	}
	if(ss%2==0){
		z=ss/2;
		if(a[1].s>=z){
			cout<<ss-a[1].s;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(a[i].c!=a[n+1-w].c){
				if(a[i].s>a[n+1-w].s){
				 	d=a[i].s-a[n+1-w].s;
					ans+=a[n+1-w].s;
					w++;
					while(1){
						if(d>a[n+1-w].s){
							d=d-a[n+1-w].s;
							ans+=a[n+1-w].s;
							w++;
						}else{
							a[n+1-w].s=a[n+1-w].s-d;
							ans+=d;
							break;
						}
					}
				}else{
					a[n+1-w].s=a[n+1-w].s-a[i].s;
					ans+=a[i].s;
				}
			}else{
				if(a[i].s>a[n+1-w].s){
				a[i].s=a[i].s-a[n+1-w].s;
					w++;
				}
			}
			if(a[n-w+1].id-a[n-w+1].s<=z&&a[n-w+1].id>=z){
				break;
			}
		}
	}else{
		z=ss/2+1;
		if(a[1].s>=z){
			cout<<ss-a[1].s;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(a[i].c!=a[n+1-w].c){
				if(a[i].s>a[n+1-w].s){
					int d=a[i].s-a[n+1-w].s;
					ans+=a[n+1-w].s;
					w++;
					while(1){
						if(d>a[n+1-w].s){
							d=d-a[n+1-w].s;
							ans+=a[n+1-w].s;
							w++;
						}else{
							a[n+1-w].s=a[n+1-w].s-d;
							ans+=d;
							break;
						}
					}
					
					
					
				}else{
					a[n+1-w].s=a[n+1-w].s-a[i].s;
					ans+=a[i].s;
				}
			}else{
				if(a[i].s>a[n+1-w].s){
				a[i].s=a[i].s-a[n+1-w].s;
					w++;
				}
			}
			if(a[n-w+1].id-a[n-w+1].s<=z&&a[n-w+1].id>=z){
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
