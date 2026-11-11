#include<bits/stdc++.h>
using namespace std;
long long x;
char l[100000005],r[100000005];
char str;
char s[100000005];
long long n,sum,lon,j;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long jishu=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>str;
		lon+=x;
		for(long k=1;k<=x;k++){
			s[jishu]=str;
			jishu++;
		}
	}
	if(lon%2!=0){
		for(long i=0;i<(lon+1)/2-1;i++){
			l[i]=s[i];
		}
		for(long i=lon-1;i>(lon+1)/2-1;i--){
			r[j]=s[i];
			j++;
		}
		for(long i=0;i<(lon+1)/2;i++){
			if(l[i]!=r[i])sum++;
		}
		cout<<sum;
	}
	else{
		for(long i=0;i<lon/2;i++){
			l[i]=s[i];
		} 
		for(long i=lon-1;i>=lon/2;i--){
			r[j]=s[i];
			j++;
		}
		for(long i=0;i<lon/2;i++){
			if(l[i]!=r[i])sum++;
		}
		cout<<sum;
	}
	return 0; 
} 
