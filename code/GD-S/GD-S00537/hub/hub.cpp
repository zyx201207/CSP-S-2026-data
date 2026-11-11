#include<bits/stdc++.h>
using namespace std;
bool f;
int c,t,n,k,a,b,in[1000001];
int main(){
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		f=false;
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>a>>b;
			in[a]++;
			in[b]++;
			if((in[a]==n-1)||(in[b]==n-1)){
				f=true;
			}
		}
		if(f){
			cout<<2<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	return 0;
}
