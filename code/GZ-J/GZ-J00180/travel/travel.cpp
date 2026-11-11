//CZ-J00180  遵义市汇川区第一小学 张馨艺
#include<bits/stdc++.h>
using namespace std;
char a[4],b[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	cin>>n;
	for(int i=1;i<=3;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	if(n!=m){
		cout<<"0000";//1
	}else if(n==m){
		cout<<"1";//1
		if(a[1]==b[1] and a[2]==b[2]){
			cout<<"1";//2
			if((a[3]==b[3]) or ((a[3]>='A' and a[3]<='C') and (b[3]>='A' and b[3]<='C')) or ((a[3]=='D' or a[3]=='F') and (b[3]=='D' or b[3]=='F'))){
				cout<<"1";//3
				if(a[3]=='A' and b[3]=='B'){
					cout<<"1";//4
				}else if(a[3]=='B' and b[3]=='C'){
					cout<<"1";//4
				}else if(a[3]=='D' and b[3]=='F'){
					cout<<"1";//4
				}else{
					cout<<"0";//4
				}
			}else{
				cout<<"0";//3
				if(a[3]=='A' and b[3]=='B'){
					cout<<"1";//4
				}else if(a[3]=='B' and b[3]=='C'){
					cout<<"1";//4
				}else if(a[3]=='D' and b[3]=='F'){
					cout<<"1";//4
				}else{
					cout<<"0";//4
				}
				
			}
		}else{
			cout<<"0";//2
			cout<<"0";//3
				if(a[3]=='A' and b[3]=='B'){
					cout<<"1";//4
				}else if(a[3]=='B' and b[3]=='C'){
					cout<<"1";//4
				}else if(a[3]=='D' and b[3]=='F'){
					cout<<"1";//4
				}else{
					cout<<"0";//4
				}
			}
		}
	return 0;
}
 
