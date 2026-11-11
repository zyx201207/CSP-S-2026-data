#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
string s;	
int main() {
	
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>a[i]>>c;
		s+=c;
	}
	long long r=0,l=0,m=0;
	for(int i=1;i<=n;i++)
	{
		if(i-r>=n+1-i+l) break;
		if(s[i-r-1]!=s[n-i+l]){
			if(a[i-r]>a[n+1-i+l]){
				a[i-r]-=a[n+1-i+l];
				m+=a[n+1-i+l];
				r++;
			}
			else if(a[i-r]<a[n+1-i+l]){
				a[n+1-i+l]-=a[i-r];
				m+=a[i-r];
				l++;
			}
			else m+=a[n+1-i+l];
		}
		else if(s[i-r-1]==s[n-i+l]&&a[i-r]!=a[n+1-i+l]){
			if(a[i-r]>a[n+1-i+l]){
				a[i-r]-=a[n+1-i+l];
				r++;
			}
			else if(a[i-r]<a[n+1-i+l]){
				a[n+1-i+l]-=a[i-r];
				l++;
			}
		}
		
	}
	cout<<m;
}