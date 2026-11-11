#include<bits/stdc++.h>
using namespace std;
string x,y,a,b;
long long n,m,k,l,sum,cnt,num,hum,o,p;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		cin>>x>>a;
		cin>>y>>b;
		o=a.size()-1;
		p=b.size()-1;
		for(long long i=0;i<x.size();i++){
			if(x[i]>='0'&&x[i]<='9'){
				sum+=x[i];
			}
		}
		for(long long i=0;i<y.size();i++){
			if(y[i]>='0'&&y[i]<='9'){
				cnt+=y[i];
			}
		}
		if(cnt==sum){
			n=1;
		}else{
			n=0;
		}
		if(n==0){
			cout<<"0000";
			return 0;
		}
		for(long long i=0;i<a.size();i++){
			if(a[i]>='0'&&a[i]<='9'){
				num+=a[i];
			}
		}
		for(long long i=0;i<b.size();i++){
			if(b[i]>='0'&&b[i]<='9'){
				hum+=b[i];
			}
		}
		if(num==hum&&n!=0){
			m=1;
		}else{
		m=0;
		}
		if(m==0){
			cout<<"1000";
			return 0;
		}
	   if(a[o]=='A'){
	   	if(b[p]=='B'||b[p]=='C'){
	   		k=1;
		   }else{
		   	k=0;
		   }
	   }else if(a[o]=='B'){
	   	if(b[p]=='A'||b[p]=='C'){
	   		k=1;
		   }else{
		   	k=0;
		   }
	   }else if(a[o]=='C'){
	   	if(b[p]=='A'||b[p]=='B'){
	   		k=1;
		   }else{
		   	k=0;
		   }
	   }else if(a[o]=='D'){
	   	if(b[p]=='F'){
	   		k=1;
		   }else{
		   	k=0;
		   }
	   }else  if(a[o]=='F'){
	   	if(b[p]=='D'){
	   		k=1;
		   }else{
		   	k=0;
		   }
	   }
	   if(k==0){
	   	cout<<"1100";
	   	return 0;
	   }
	   if(k==1){
	   	if(a[o]=='D'){
	   		if(b[p]=='F'){
	   			l=1;
			   }else{
			   	l=0;
			   }
		   }else if(a[o]=='F'){
		   	if(b[p]=='D'){
		   		l=1;
			   }else{
			   	l=0;
			   }
		   }else{
		   	if(a[o]+1==b[p]||a[o]-1==b[p]){
		   		l=1;
			   }else{
			   	l=0;
			   }
		   }
	   }
	   cout<<n<<m<<k<<l;
	   	   return 0;
}
