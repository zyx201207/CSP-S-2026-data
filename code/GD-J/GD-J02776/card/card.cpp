#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	int n,m;
	cin>>n>>m;
	int a[n];
	int b[m]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int c[m]={0};
		int d=0;
		string s=""; 
		for(int j=i;j<n;j++){
			c[j]++;
			d=d*10+c[j];
			if(c[j]>1){
				int e=0;
				s=d;
				for(int l=i;l<n;l++){
					if(s[l]==s[j]){
						e=e*10+s[l];
						break;
					}
					else e=e*10+s[l];
				}
				d=e;
			}
		}
		s=d;
		for(int j=i;j<n;j++){
			cout<<s<<endl;
			b[s[j]]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
}
