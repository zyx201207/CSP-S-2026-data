#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100; 
int n;
long long a[N],s[N]={0};
int sm,md;
char c[N];
int cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
		sm+=a[i];
		if(i>1&&c[i]==c[i-1]){
			s[i-1]=s[i];
			a[i-1]+=a[i];
			n--;
		    i--;
		}
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}else if(n==2){
		if(c[1]==c[2])cout<<0<<endl;
		else cout<<min(a[1],a[2])<<endl;
		return 0;
	}
	md=sm/2;
	if(sm%2==1)md++;
	int i=1,j=n;
	for(;i<=n&&s[i]<=md&&i<j;i++){
		for(;j>=1&&sm-s[j]<s[i]&&j>i;j--){
			if(c[i]!=c[j]){
				if(sm-s[j-1]<=s[i]&&sm-s[j]>=s[i-1]){
					cnt+=a[j];
				}else if(sm-s[j-1]<=s[i]){
					cnt=cnt+sm-s[j-1]-s[i-1];
				}else if(sm-s[j]>=s[i-1]){
					cnt=cnt+s[i]-sm+s[j]; 
				}
			}
			if(sm-s[j-1]>s[i]){break;} 
		}
	} 
	if(s[i]>md){
		for(;j>=1&&j>i;j--){
			if(c[i]!=c[j]){
				if(sm-s[j-1]<=md&&sm-s[j]>=s[i-1]){
					cnt+=a[j];
				}else if(sm-s[j-1]<=md){
					cnt=cnt+sm-s[j-1]-s[i-1];
				}else if(sm-s[j]>=s[i-1]){
					cnt=cnt+md-sm+s[j]; 
				}
			}
		}
	}	
	cout<<cnt;
	return 0;
}
