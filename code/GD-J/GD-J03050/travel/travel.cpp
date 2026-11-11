#include <bits/stdc++.h>
using namespace std;
char a[10];
int st[100005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}st[a[5]]=1;st[a[10]]=1;
	for(int i=1;i<=1;i++){
	
	if(a[1]==a[6]&&a[2]==a[7]){cout<<"1";
	}else{cout<<"0000";break;
	}
	if(a[3]==a[8]&&a[4]==a[9]){
		cout<<"1";
	}else{cout<<"000";break;
	}
	int cnt=0;
	if(st[65]==1&&st[66]==1){cnt+=2;
	}
	else if(st[65]==1&&st[67]==1){cnt+=1; 
	}
	else if(st[66]==1&&st[67]==1){cnt+=2;
	}else if(st[68]==1&&st[70]==1){cnt+=2;
	}
	
	if(cnt>=1){
		cout<<"1";
		
	}else{cout<<"0";
	}
	if(cnt==2){
		cout<<"1";
	}else{cout<<"0";
	}}
	return 0;
}
