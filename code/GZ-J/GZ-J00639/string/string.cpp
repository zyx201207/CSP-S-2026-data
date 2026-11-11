//李昊阳 个人报名 GZ-J00639
#include <bits/stdc++.h> 
using namespace std;
int n;
string S[200005],w[200005],h[200005];
int j=0,z=0,p=0,num=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		char b;
		cin>>a>>b;
		for(int i=0;i<a;i++){
			S[j]=b;
			j++;
		}
		z+=a;
	}
	for(int i=0;i<z;i++){
		if(i<z/2){
			w[i]=S[i];
		}
		if(i>z/2){
			h[p]=S[i];
			p++;
		}
	}
	for(int i=0;i<z/2;i++){
		
		
		
		if(w[i]!=h[i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
