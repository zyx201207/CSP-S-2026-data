 #include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c1,c2;
	cin>>a>>c1>>b>>c2;
	if(a==b){
		cout<<1;
	}
	else {
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	bool flag=true;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			flag=false;
		}
	}
	if(flag){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(c1[2]=='C' && c2[2]=='D'){
		cout<<0;
		cout<<0;
		return 0;
	}
	else if((c1[2]+=1)==c2[2]){
		if(c1[2]!='C'){
			cout<<11;
		}
	}
	else if((c1[2]-=1)==c2[2]){
		 if(c1[2]!='F'){
		 	cout<<11;
		 }
	}
	else {
		if(('A'<=c1[2]&&c1[2]<='C')&&('A'<=c2[2]&&c2[2]<='C')||('D'<=c1[2]&&c1[2]<='F')&&('D'<=c2[2]&&c2[2]<='F')){
			cout<<10;
		}	
	}
}
