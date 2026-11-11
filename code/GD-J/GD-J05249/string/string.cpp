#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],s,q[5000005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	if(s<=5*1e6){
		if(s%2==0){
			int p=1;
			for(int i=1;i<=n;i++){
				for(int j=p;j<=p+a[i]-1;j++){
					q[j]=c[i];
				}
				p+=a[i];
			}
			int mid=s/2,aut=s/2+1,fix=0;
			while(mid>=1&&aut<=s){
				if(q[mid]!=q[aut]) fix++;
				mid--;
				aut++;
			}
			cout<<fix;
		}else{
			int p=1;
			for(int i=1;i<=n;i++){
				for(int j=p;j<=p+a[i]-1;j++){
					q[j]=c[i];
				}
				p+=a[i];
			}
			int mid=s/2+1,aut=s/2+1,fix=0;
			while(mid>=1&&aut<=s){
				if(q[mid]!=q[aut]) fix++;
				mid--;
				aut++;
			}
			cout<<fix;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
