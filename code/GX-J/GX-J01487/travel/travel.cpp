#include<bits/stdc++.h>
using namespace std;
string s,s1;
int arr[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c,c1;
	cin>>c>>s>>c1>>s1;
	for(int i=1;i<=4;i++){
	if(c==c1){
		arr[1]=1;
	}else{
		arr[1]=0;
		break;
	}
	if(s[1]==s1[1]){
		arr[2]=1;
	}
	else{
		arr[2]=0;
		break;
	}
	if(s[2]>='D'||s1[2]>='D'){
		arr[3]=0;
		break;
	}
	else if(s[2]-1==s1[2]||s[2]-2==s1[2]||s[2]+1==s1[2]){
		arr[3]=1;
	}
	if(s[2]+1==s1[2]||s[2]-1==s1[2]||s[2]+2==s[2]||s[2]-2==s[2]){
		arr[4]=1;
	}else{
		arr[4]=0;
	}		
}
	for(int i=1;i<=4;i++){
		cout<<arr[i];
	}
	return 0;
}
