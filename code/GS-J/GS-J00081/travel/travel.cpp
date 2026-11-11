#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[10];
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	for(int i=1;i<=10;i++){
		if(a[1]==a[6]&&a[2]==a[7]){
		if(a[3]==a[8]){
		   if(a[4]==a[9])	{
		   	if(a[5]=='A'&&a[10]=='B'){
		   		cout<<"1111";
		   		break;
			   }else if(a[5]=='B'&&a[10]=='C'){
			   	cout<<"1111";
			   	break;
			   }else if(a[5]=='B'&&a[10]=='A'){
			   	cout<<"1111";
			   	break;
			   }else if(a[5]=='C'&&a[10]=='B'){
			   	cout<<"1111";
			   	break;
			   }else if(a[5]=='D'&&a[10]=='F'){
			   	cout<<"1111";
			   	break;
			   }else if(a[5]=='F'&&a[10]=='D'){
			   	cout<<"1111";
			   	break;
			   }else if(a[5]=='A'&&a[10]=='C'){
			   	cout<<"1110";
			   	break;
			   }else if(a[5]=='C'&&a[10]=='A'){
			   	cout<<"1110";
			   	break;
			   }else{
			   	cout<<"1100";
			   	break;
			   }
		   }else{
		   	cout<<"1100";
		   	break;
		   }
		}else{
			cout<<"1000";
			break;
		}
		}else{
			cout<<"0000";
			break;
		}
	}
	return 0;
}
