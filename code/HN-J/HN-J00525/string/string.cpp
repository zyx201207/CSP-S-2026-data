#include<bits/stdc++.h>
using namespace std;
long long a[222222],b[222222];
char s[222222];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long len=0,m=0;
	char c;
	bool poi=0;
	string amn="";
	if(n==1){
		cout<<"0\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c;
		len+=b[i];
		s[i]=c;
		if(b[i]>=500){
			poi=1;
		}
	}
	if(poi==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=b[i];j++){
				amn+=s[i];
			}
		}
		string s2=amn.substr(0,len/2+len%2-1),s3=amn.substr(len/2+len%2);
		reverse(s2.begin(),s2.end());
	//	cout<<s2<<'\n'<<s3<<'\n';
		for(int i=0;i<s3.length();i++){
			if(s2[i]!=s3[i]){
				m++;
			}
		}
		cout<<m<<'\n';
		return 0;
	}
	if(poi==1){
		long long x=len/2+(len&1);
		long long x1=0,p=0,w1,w2;
		for(int i=1;i<=n;i++){
			x1+=b[i];
			if(x1>=x){
				p=i;
				w2=x1-x;
				w1=b[i]-w2;
				break;
			}
		}
		n++;
		char op;
		long long qw;
		for(int i=1;i<=n;i++){
			if(i<p){
				a[i]=b[i];
			}
			if(i==p){
				a[i]=w1-1;
				a[i+1]=w2-1;
			}
			if(i>p&&i!=p+1){
				a[i+1]=b[i];
			}
		}
		long long g=0,g2=0;
		for(int i=n;i>=p;i--){
			while(a[i]>0){
				if(s[i]==s[g]){
					if(a[i]>a[g]){
						a[i]-=a[g];
						g++;
					}
					else{
						a[g]-=a[i];
						if(a[g]==0){
							g++;
						}
						break;
					}
				}
				else{
					if(a[i]>a[g]){
						a[i]-=a[g];
						m+=a[g];
						g++;
					}
					else{
						a[g]-=a[i];
						m+=a[i];
						if(a[g]==0){
							g++;
						}
						break;
					}					
				}
			}
		}
	}
	cout<<m<<'\n';
	return 0;
}

