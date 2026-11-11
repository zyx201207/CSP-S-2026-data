#include<bits/stdc++.h>
using namespace std;
const int M=1e5*2+10;
long long a[M];
int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	//cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int B=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(((a[i]&1)==1)&&B!=2){
			B=1;
		}
		else B=2;
	}
	if(B==1){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	B=0;
	for(int i=1;i<=n;i++){
		if(a[i]==(i-1)&&B!=2){
			B=1;
		}
		else B=2;
	}
	if(B==1){
		long long p=a[n];
		for(int i=1;i<m;i++){
			p=p&a[n-i];
		}
		cout<<p;
		return 0;
	}
	B=0;
	for(int i=1;i<=n;i++){
		if(a[i]<4&&B!=2)B=1;
		else B=2;
	}
	if(B==1){
		if(m%2==1){
			int p3=0,p2=0,p1=0,p0=0;
			for(int i=1;i<=n;i++){
				if(a[i]==3)p3++;
				if(a[i]==2)p2++;
				if(a[i]==1)p1++;
				if(a[i]==0)p0++; 
			}
			if(p3>=m){
				cout<<3;
				return 0;
			}
			m-=p3;
			if(m%2==0){
				int u=m/2;
				if(u<=(p0+p2)){
					cout<<3;
					return 0;
				}
			}
		}
	}
	if(m==1){
		long long maxa=-1;
		for(int i=1;i<=n;i++){
			maxa=max(maxa,a[i]);
		}
		cout<<maxa;
		return 0;
	}
	if(m==n){
		long long maxa=a[1];
		for(int i=2;i<=n;i++){
			maxa=(maxa&a[i]);
		}
		cout<<maxa;
		return 0;
	}
	sort(a+1,a+1+n);
	int maxa=-1,ans,pos=m-1;
	for(int i=1;i<=n;i++){
		ans=a[i];
		pos=m-1;
		for(int j=i+1;pos;j++){
			ans=(ans&a[j]);
			pos--;
		}
		maxa=max(maxa,ans);
	}
	cout<<maxa;
	return 0;
}
