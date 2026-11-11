#include<bits/stdc++.h>
using namespace std;
char ch[500000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		int l;
		cin>>l>>a;
		
		//cout<<l<<'\n';
		
		for(int j=len+1;j<=len+l;j++){
			ch[j]=a;
			//cout<<ch[j]<<' '<<j;
		}
		len+=l;
		if(len>500000000) break;
		//for(int j=1;j<=len;j++){
		//	cout<<ch[j]<<' ';
		//}
		//cout<<'\n';
	}
	//for(int i=1;i<=len;i++){
	//	cout<<ch[i]<<' ';
	//}
	if(len>500000000){
		cout<<0;
		return 0;
	}
	long long temp,flag;
	flag=len%2;
	if(len%2==0){
		temp=len/2;
	}
	else{
		temp=len/2+1;
	}
	for(int i=len;i>=temp;i--){
		if(ch[i]!=ch[len-i+flag]){
			ans++;
			//ch[i]=ch[len-i];
		}
	}
	cout<<ans;
	//cout<<'\n'<<n<<' '<<len;
	return 0;
}
