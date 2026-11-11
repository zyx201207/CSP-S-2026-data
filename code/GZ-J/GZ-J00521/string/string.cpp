//GZ-J00521 ÍõÐÞÆë 
#include<bits/stdc++.h>
using namespace std;
long long n,a[100000005],d,l;
char c[30],ans[100000005],s[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1) {cout<<0; return 0;}
	
	for(int i=1,q=0;i<=n;i++){
		cin>>a[i]>>c[i];
		
		for(int j=1;j<=a[i];j++){
			ans[j]=c[i];
			s[q]=ans[j];
			q++;
			}
			if(i==n){
				d=q;
			}
		}
		for(int g=0,h=d;g<d/2,h>d/2;g++,h--){
			if(s[g]!=s[h]) l+=1; 
		}
		cout<<l;
	return 0;
}
