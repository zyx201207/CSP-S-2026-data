#include<bits/stdc++.h>
using namespace std;
int s[100000][3];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	long long n;
	cin>>n;
	
	char c;
	long long m;
	long long y=0;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
	
		s[i][1]=c-'0';
		s[i][2]=m;
		y+=m;
	}
	
	long long k=0;
	long long o=n,i=1;
	long long f=0;
	while(o>i){
		
		int a,b;
		if(n-o+1>i || f!=0){
			a=f;
			b=s[o][2];
		}
		else if(n-o+1<i || f!=0){
			b=f;
			a=s[i][2];
		}
		else if(f==0){
			b=s[o][2];
			a=s[i][2];
		}
		

		if(s[o][1] != s[i][1]){
			k+=min(a,b);
			f=max(a,b)-min(a,b);
		}
		if(a<b){
			i+=1;
		}
		else if(a>b){
			o--;
		}
		else{
			i++;
			o--;
		}
		
	}
	cout<<k;
}
