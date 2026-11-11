#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a[200005],gesu=0,a1=0,Char3=1;
	char Char[210005],Char2[210005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>Char2[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			Char[Char3]=Char2[i];Char3++;
		}
		}
		Char3=Char3-1;
	//for(int i=1;i<Char3;i++){
	//	cout<<Char[i];
	//}
	if(n==1){cout<<0;return 0;}
	//for(int i=1;i<=n;i++){a1=a1+a[i];}//cout<<a1<<"#"<<endl;
	for(int i=1;i<=(Char3+1)/2;i++){
		if(Char[i]==Char[Char3-i+1]) gesu++;
		//cout<<gesu<<endl;
		}
		if(gesu==(Char3+1)/2){cout<<0;return 0;}
		if(Char3%2==0){
			cout<<(Char3-2)/2;
		} 
		if(Char3%2==1){
			cout<<(Char3-1)/2;
		} 
return 0;}
