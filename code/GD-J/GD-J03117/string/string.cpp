#include<bits/stdc++.h>
using namespace std;
int n,c;
long long ans,m,a[200009],b[200009];
char s[200009],d[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i]>>s[i];
	for(int i=0;i<n;i++){
		m+=a[i];
		if(s[i]!=s[i+1]){
			d[c]=s[i];
			b[c++]=m;
			m=0;
		}
	}
	for(int i=0,j=c-1;i<j;){
		if(d[i]!=d[j]){
			if(b[i]>b[j]){
				ans+=b[j];
				b[i]-=b[j];
				j--;
			}
			else if(b[i]<b[j]){
				ans+=b[i];
				b[j]-=b[i];
				i++;
			}
			else{
				ans+=b[i];
				i++;
				j--;
			}
		}
		else{
			if(b[i]>b[j]){
				b[i]-=b[j];
				j--;
			}
			else if(b[i]<b[j]){
				b[j]-=b[i];
				i++;
			}
			else{
				i++;
				j--;
			}
		}
	}
	cout<<ans; 
}

