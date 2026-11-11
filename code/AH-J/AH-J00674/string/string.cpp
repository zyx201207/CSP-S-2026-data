#include<bits\stdc++.h> 
using namespace std;
long long n,ex[100000010],h=0,a;
char ls[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ex[i]>>ls[i];
		a=a+ex[i];
	}
	for(int i=1;i<=n;i++){
	 if(ls[i]!=ls[i+1])	{
	 	if(ex[i]>=ex[i+1]){
	 		h=h+ex[i+1];
	 		ls[i+1]=ls[i];
		 }
	 	else{
	 		ls[i]=ls[i+1];
	 		h=h+ex[i];
	}
	 }
	 else if(ls[i]!=ls[i+1]&&ls[i+1]!=ls[i+2]&&ls[i]!=ls[i+2]){
	 	if(a%2==0){
	 		a=a/2;
	 		cout<<a;
	 		return 0;
		 }
		 if(a%2==1){
		 	a=a/2;
		 	a=a-1;
		    cout<<a;
		    return 0;
		 }
	 }
	}

   cout<<h;
	return 0;
}
