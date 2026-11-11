#include<bits/stdc++.h> 
using namespace std;
string a,b;
string x,y;
int sum,sumi;
char s,d;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>x>>y;
	if(a==x){
			cout<<1;	}
	else {
	cout<<0<<0<<0<<0;return 0;}


	int i=0;
	while(b[i]>='0'&&b[i]<='9'){
		sum+=sum*10+b[i]-'0';i++;
	}i=0;
	while(y[i]>='0'&&y[i]<='9'){
		sumi+=sumi*10+y[i]-'0';i++;
	}
	if(sum==sumi)cout<<1;
		else {
	cout<<0<<0<<0;return 0;}
	

	int u=b.size(),o=y.size();
	
	for(int j=0;j<u;j++){
		if(b[j]<'0'||b[j]>'9')s+=b[j];
	}	for(int j=0;j<o;j++){
		if(y[j]<'0'||y[j]>'9')d+=y[j];
	}
	if((s-'0')>=17&&(s-'0')<=19&&(d-'0')>=17&&(d-'0')<=19){
		cout<<1;
		if(abs((s-'0')-(d-'0'))<=1){
		cout<<1;return 0;}
		else {
		cout<<0;return 0;}
	}
	else if((s=='D'&&d=='F')||(s=='F'&&d=='D')){
		cout<<1<<1;return 0;
	}
	else {
	cout<<0<<0;return 0;}
	return 0;
}

