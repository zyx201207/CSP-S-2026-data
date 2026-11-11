#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],z,c[30],d[30],t,w,cnt;
string s,b;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s[z]+=b[i];
		}
	}
	for(int i=0;i<s.size();i++){
		int x=s.size()/2;
		if(s.size()%2==1){
			x++;
			for(int j=0;j<=x;i++){
				c[1+abs('a'-s[j])]++;
			}
			for(int j=x-1;j<s.size();i++){
				d[1+abs('a'-s[j])]++;
			}
			for(int j=0;j<=x;j++){
				w+=c[i];
				t+=d[i];
			}
			if(w>t){
				for(int j=0;j<=x;j++){
					if(c[i]!=d[i]){
						d[i]=c[i];
						cnt++;
					}
				}
			}
			else{
				for(int j=0;j<=x;j++){
					if(c[i]!=d[i]){
						c[i]=d[i];
						cnt++;
					}
				}
			}
		}
		else{
			for(int j=0;j<=x;i++){
				c[1+abs('a'-s[j])]++;
			}
			for(int j=x-1;j<s.size();i++){
				d[1+abs('a'-s[j])]++;
			}
			for(int j=0;j<=x;j++){
				w+=c[i];
				t+=d[i];
			}
			if(w>t){
				for(int j=0;j<=x;j++){
					if(c[i]!=d[i]){
						d[i]=c[i];
						cnt++;
					}
				}
			}
			else{
				for(int j=0;j<=x;j++){
					if(c[i]!=d[i]){
						c[i]=d[i];
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}

