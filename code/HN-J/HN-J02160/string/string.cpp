#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,l=1;
	cin>>n;
	int s[n+5]={0};
	char m[n+5]={0};
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>m[i];
		num+=s[i];
	}
	char a[num+5]={0};
	int t[n+5]={1};
	for(int i=1;i<=n;i++){
		while(s[i]/10>0){
			s[i]/=10;
			t[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i];j++){
			a[l]=m[i];
			l++;
		}	
	}
	bool x=1;
	for(int i=1;i<=n;i++){
		if(m[1]!=m[i]){
			x=0;
		}
	}
	if(x==1){
		cout<<"0";	
		return 0;
	} 
	int l2=0;
	if(l%2==0){
		l2=l/2;
	}else{
		l2=l/2+1; 
	}
	int c,d;
	c=1,d=l;
	for(int i=1;i<l2;i++){
		int c,d;
		c=1,d=l;
		if(a[d]!=a[c]){
			sum++;
			for(int lll1=1;lll1<t[c];lll1++){
				sum*=10;
			}
			if(t[c]>t[d]) break;
			for(int lll2=1;lll2<t[d]-t[c];lll2++){
				sum*=10;
			}
		}
		c++;
		d--;
	} 
	cout<<sum;
	return 0;
}
