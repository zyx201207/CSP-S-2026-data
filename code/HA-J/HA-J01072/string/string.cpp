#include<bits/stdc++.h>

using namespace std;
int l_n;
long long k,l_a[2000060],nn;
char l_c[2000060];
//string l_s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l_n;
	for(int i=1;i<=l_n;i++){
		cin>>l_a[i]>>l_c[i];
	//	l_s[++k]=l_a[i];
		//l_s[++k]=l_c[i];
		nn+=l_a[i];
	}
	if(l_n==1){
		cout<<0;
		return 0;
	}
	if(l_n==2){
		
			if(l_c[1]!=l_c[2]){
				cout<<min(l_a[1],l_a[2]);
			}
			else cout<<0;
		
	}
	//cout<<"p";
	

	return 0;
}
