#include<iostream>
using namespace std;
int n,m,l=0,num[100000001];long long ans=0;
string a;char s[100000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a+=' ';
	for(int i=1;i<=n;i++){
		cin>>num[i]>>s[i];
	}
	int f=1,r=n;
	while(f<r){
		//cout<<num[f]<<" "<<num[r]<<endl; 
		if(num[f]>num[r]){
			num[f]-=num[r];
			if(s[f]!=s[r]) ans+=num[r];
			num[r]=0;
			r--;
		}
		else if(num[f]<num[r]){
			num[r]-=num[f];
			if(s[f]!=s[r]) ans+=num[f];
			num[f]=0;
			f++;
		}
		else if(num[f]==num[r]){
			if(s[f]!=s[r]) ans+=num[f];
			num[f]=0;num[r]=0;
			f++;r--;
		}
		//cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
