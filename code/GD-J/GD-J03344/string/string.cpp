#include<bits/stdc++.h>
using namespace std;
string a;
char c[200010];
long long b[200010],n,sum,cnt;
bool t=false;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i-cnt]>>c[i-cnt];
		if(c[i-cnt]==c[i-cnt-1]){
			b[i-cnt-1]+=b[i-cnt];
			cnt++;
		}
	}
	if((n-cnt)==1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=(n-cnt)/2;i++){
		if(c[i]!=c[n-i+1]){
			sum+=max(b[i],b[n-i+1]);
			if(b[n-i+1]>b[i])b[i]-=b[n-i+1];
			else if(b[i]>b[n-i+1])b[n-i+1]-=b[i];
		}else {
			sum+=abs(b[n-i+1]-b[i]);
			if(b[n-i+1]>b[i])b[i]-=b[n-i+1];
			else if(b[i]>b[n-i+1])b[n-i+1]-=b[i];
		}
		if(b[i]<0)b[i+1]+=b[i];
		if(b[n-i-1]<0)b[n-i-2]+=b[n-i-1];
	}
	cout<<sum<<endl;
	return 0;
} 
