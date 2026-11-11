#include<bits/stdc++.h>
using namespace std;

const int Nd=200050;
long long a[Nd],sum=0,n,op[Nd],opp=-1;
string s="";
char c[Nd],uu;

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
	cin>>n;
if(n<=1500){
long long hhj;
string kke;
for(int i=1;i<=n;i++){
	for(int j=1;j<=a[i];j++){
	kke=kke+c[i];
}
hhj+=a[i];
}
for(int i=0;i<n/2;i++){
	if(kke[i]!=kke[hhj-i]){
	sum++;
	}
}
cout<<sum;
		}
		else{
			
			for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		op[int(c[i]-96)]+=a[i];
		opp=max(opp,op[int(c[i]-96)]);
		if(opp==op[int(c[i]-96)]) uu=c[i];
	}
	sum=-opp;
	for(int i=1;i<=26;i++){
		sum+=op[i];
	}
cout<<sum;
			}
	
return 0;
}
