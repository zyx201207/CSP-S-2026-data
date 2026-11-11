#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];char c[N];
int main(){
	ifstream fin("string.in");
	ofstream fout("string.out");
	int n;long long ans=0;
	bool che=false;
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>a[i]>>c[i];
	}
	for(int i=1;i<n&&!che;i++) if(c[i]!=c[i+1]) che=true;
	string t;char x='m';
	for(int i=1;i<=n/2+n%2&&che;i++){
		if(t.length()==0){
			if(c[i]!=c[n-i+1]){
				if(a[i]!=a[n-i+1]){
					if(a[i]>a[n-i+1]){
						x='l';
						for(int j=1;j<=a[i]-a[n-i+1];j++) t=t+c[i];
						ans=ans+a[i]-a[n-i+1];
					}
					if(a[i]<a[n-i+1]){
						x='r';
						for(int j=1;j<=a[n-i+1]-a[i];j++) t=t+c[n-i+1];
						ans=ans+a[n-i+1]-a[i];
					}
				}
				else{
					ans=ans+a[i];
				}
			}
			else{
				if(a[i]!=a[n-i+1]){
					if(a[i]>a[n-i+1]){
						x='l';
						for(int j=1;j<=a[i]-a[n-i+1];j++) t=t+c[i];
						ans=ans+a[i]-a[n-i+1];
					}
					if(a[i]<a[n-i+1]){
						x='r';
						for(int j=1;j<=a[n-i+1]-a[i];j++) t=t+c[n-i+1];
						ans=ans+a[n-i+1]-a[i];
					}
				}
			}
		}
		else{
			if(x=='l'){
				while(t.length()>0&&a[n-i+1]>0){
					if(t[0]!=c[n-i+1]) ans++;
					t.erase(0,1);
					a[n-i+1]--;
				}
				if(t.length()==0&&a[n-i+1]>0){
			if(c[i]!=c[n-i+1]){
				if(a[i]!=a[n-i+1]){
					if(a[i]>a[n-i+1]){
						x='l';
						for(int j=1;j<=a[i]-a[n-i+1];j++) t+=c[i];
						ans=ans+a[i]-a[n-i+1];
					}
					if(a[i]<a[n-i+1]){
						x='r';
						for(int j=1;j<=a[n-i+1]-a[i];j++) t+=c[n-i+1];
						ans=ans+a[n-i+1]-a[i];
					}
				}
				else{
					ans=ans+a[i];
				}
			}
			else{
				if(a[i]!=a[n-i+1]){
					if(a[i]>a[n-i+1]){
						x='l';
						for(int j=1;j<=a[i]-a[n-i+1];j++) t+=c[i];
						ans=ans+a[i]-a[n-i+1];
					}
					if(a[i]<a[n-i+1]){
						x='r';
						for(int j=1;j<=a[n-i+1]-a[i];j++) t+=c[n-i+1];
						ans=ans+a[n-i+1]-a[i];
					}
				}
			}
				}
				else{
					for(int j=1;j<=a[i];j++) t=t+c[i];
				}
			}
			if(x=='r'){
				while(t.length()>0&&a[i]>0){
					if(t[0]!=c[i]) ans++;
					t.erase(t.length()-1,1);
					a[i]--;
				}
				if(t.length()==0&&a[i]>0){
			if(c[i]!=c[n-i+1]){
				if(a[i]!=a[n-i+1]){
					if(a[i]>a[n-i+1]){
						x='l';
						for(int j=1;j<=a[i]-a[n-i+1];j++) t+=c[i];
						ans=ans+a[i]-a[n-i+1];
					}
					if(a[i]<a[n-i+1]){
						x='r';
						for(int j=1;j<=a[n-i+1]-a[i];j++) t+=c[n-i+1];
						ans=ans+a[n-i+1]-a[i];
					}
				}
				else{
					ans=ans+a[i];
				}
			}
			else{
				if(a[i]!=a[n-i+1]){
					if(a[i]>a[n-i+1]){
						x='l';
						for(int j=1;j<=a[i]-a[n-i+1];j++) t+=c[i];
						ans=ans+a[i]-a[n-i+1];
					}
					if(a[i]<a[n-i+1]){
						x='r';
						for(int j=1;j<=a[n-i+1]-a[i];j++) t+=c[n-i+1];
						ans=ans+a[n-i+1]-a[i];
					}
				}
			}
				}
				else{
					for(int j=1;j<=a[n-i+1];j++) t=t+c[n-i+1];
				}
			}
		}
	}
	fout<<ans;
	fin.close();
	fout.close();
} 
