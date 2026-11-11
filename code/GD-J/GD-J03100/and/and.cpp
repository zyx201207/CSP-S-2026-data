#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200009];
ll n,m;
bool if1[200009];
string hd2(int a){
	string b;
	while(a!=0){
		b+=char(a%2+'0');
		a/=2;
	}
	string c;
	for(int i=b.length()-1;i>=0;i--){
		c+=b[i];
	}
	return b;
}
int hd1(int a,int b){
	string x=hd2(a),y=hd2(b);
	int xyl=max(x.length(),y.length());
	//cout<<x<<" "<<y<<endl;
	string sum;
	if(x.length()<y.length()){
		string x1=x;
		int xlength=x.length();
		x="";
		for(int i=1;i<=y.length()-xlength;i++){
			x+='0';
		}
		x+=x1;
	}else{
		if(x.length()>y.length()){
			string y1=y;
			int ylength=y.length();
			y="";
			for(int i=1;i<=x.length()-ylength;i++){
				y+='0';
			}
			y+=y1;
		}
	}
	//cout<<x<<" "<<y<<endl;
	for(int i=0;i<max(x.length(),y.length());i++){
		if(i>x.length()-1||i>y.length()-1){
			sum+='0';
		}else{
			if(x[i]!=y[i]){
				sum+='0';
			}else{
				if(x[i]=='0'&&y[i]=='0'){
					sum+='0';
				}else{
					sum+='1';
				}
			}
		}
	}
	int suml=sum.length();
	if(suml>xyl){
		while(sum[0]!='1'){
			for(int i=0;i<suml;i++){
				sum[i]=sum[i+1];
			}
			suml--;
		}
	}
	//cout<<sum<<endl;
	int num=0;
	for(int i=0;i<suml;i++){
		if(sum[i]=='1'){
			//cout<<pow(2,i-i1)<<endl;
			num+=(sum[i]-'0')*pow(2,i);
		}
	}
	//cout<<num<<endl;
	return num;
}
ll b[100009];
ll max1=-INT_MAX;
void hd3(int g){
	if(g==m+1){
		ll sum=b[1];
		//cout<<b[1]<<" ";
		for(int i=2;i<=m;i++){
			//cout<<b[i]<<" ";
			sum=hd1(sum,b[i]);
		}
		//cout<<endl<<sum<<endl;
		if(max1<sum){
			max1=sum;
		}
		return;	
	}
	for(int i=1;i<=n;i++){
		if(if1[i]==true){
			if1[i]=false;
			b[g]=a[i];
			hd3(g+1);
			if1[i]=true;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",sdtout);
	memset(if1,true,100009);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	hd3(1);
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

