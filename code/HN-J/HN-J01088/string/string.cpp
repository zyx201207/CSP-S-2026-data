#include<bits/stdc++.h>
using namespace std;
long long n,l,m,p,c,c1,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ans=0;
	c=n;
	int q[n+5]={0};
	string w[n+5]={"0"};
	for(long long i=1;i<=n;i++){
		cin>>q[i]>>w[i];
		l+=q[i];
	}
	if(l%2==1){
		l=l/2+1;
	} 
	else{
		l=l/2;
	}
	for(long long i=1;i<=n;i++){
		m+=q[i];
		if(m>=l){
			p=i;
			break;
		}
	}
	for(int i=1;i<=p+1;i++){
		if(w[i]==w[n+1-i]){
			q[n+i-1]-=q[i];
			if(q[n+1-i]<0){
				q[i]=0-q[n+1-i];
				q[n+1-i]=0;
				i--;
				n--;
			}
			else{
				q[i]=0;
				n++;
			}
		}
		else{
			c=q[i];
			c1=q[n+i-1];
			q[n+i-1]-=q[i];
			if(q[n+1-i]<=0){
				ans+=c1;
				q[i]=0-q[n+1-i];
				q[n+1-i]=0;
				i--;
				n--;
			}
			else{
				ans+=c;
				q[i]=0;
				n++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
