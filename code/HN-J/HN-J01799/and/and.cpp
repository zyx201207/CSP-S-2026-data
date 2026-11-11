#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m,mx;
long long a[N];
int TF(int x,int m){
	string s[N];
	int b,c,h;
	b=0;
	c=0;
	for(int i=0;i<h;i++){
		s[i]='0';
	} 
	h=0;
	for(int j=x;j<m+x;j++){
		b=a[j];
		c=a[j+1];
		while(1){
			if(b%2==1&&c%2==1){
				s[h]='1';
			}else{
				s[h]='0';
			}
			h++;
			b/=2;
			c/=2;
			if(b==0||c==0){
				break;
			}
		}
		string d;
		for(int i=h;i>=0;i--){
			d+=s[i];
		}
		long long  ans;
		ans=0;
		for(int i=0;i<d.size();i++){
			if(i==0){
				ans=ans+int(a[0])*1;
			}else{
				long long  p;
				p=1;
				for(int k=1;k<=b;k++){
					p=p*2;
				}
				ans=ans+int(a[i])*p;
			}
		} 
		if(j==m+x-1){
			return ans;
		}else{
			a[j+1]=ans;
		}
		for(int i=0;i<d.size();i++){
			if(d[i]!=0){
				d[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	 	cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		int e;
		e=i;
		mx=max(mx,TF(e,m));
	} 
	cout<<mx;
	return 0;
}


