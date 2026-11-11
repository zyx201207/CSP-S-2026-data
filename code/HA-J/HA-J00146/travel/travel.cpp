#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string p="";
	if(a==c){
		p+='1';
	}
	else if(a!=c){
		cout<<"0000\n";
		return 0;
	}
	int cnt=0,cnt2=0;
	bool ok=0;
	for(int i=1;i<b.size()-1;i++)cnt=cnt*10+(b[i]-'0');
	for(int i=1;i<d.size()-1;i++)cnt2=cnt2*10+(d[i]-'0');
	//cout<<cnt<<" "<<cnt2;
	if(cnt==cnt2){
		ok=1;
		p+='1';
		
	}
	else if(cnt!=cnt2)p+='0';
	cnt=0;
	cnt2=0;
	int sum=0;
	bool flag=0;
	
	if(ok){
		if(b[2]>='A'&&b[2]<='C')sum=1;			
		if(d[2]=='D'||d[2]=='F'){
			if(sum==1)p+='0';				
			else {
				sum=3;
				flag=1;//p+='2';
				p+='1';	
			}					
		}
		if(d[2]>='A'&&d[2]<='C'){
			if(sum==1){
				sum=4;
				flag=1;
				p+='1';
			}
			else p+='0';
		}
		
	}	
	else{
		p+='0';
	}	
	
	if(flag){
		if(sum==3)p+='1';
		if(sum==4){
			if(b[2]=='B'||d[2]=='B')p+='1';
			else p+='0';							
		}
	}
	else{
		p+='0';
	}
	cout<<p<<'\n';
	return 0;
}
