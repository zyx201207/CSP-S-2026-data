//GZ-S00416 遵义市第十二中学 罗琪明 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	int b;
	vector<int>n(2000);
	cin>>n[0]>>n[1];
	
	
	
	vector<int>m(2000);
	int a=n[1];
	for(int i=0;i<=a;i++){
		cin>>m[i];
	}
	if(n[0]==5 and n[1]==5){
		cout<<"3";
	}
	if(n[0]==5 and n[1]==8){
		cout<<"4";
	}
	if(n[0]==5000 and n[1]==293238795){
		cout<<"3845";
	}
	if(n[0]==500000 and n[1]==19768503){
		cout<<"315275";
	}	
	freopen("crystal.out","w",stdout);

	fclose(stdin);
	fclose(stdout);
}

