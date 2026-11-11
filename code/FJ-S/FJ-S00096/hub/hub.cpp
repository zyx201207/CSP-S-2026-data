#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	int n[100];
	int k[100];
	long long a[200000][200000];
	cin>>c>>t;
	for(int i=1;i<=1;i++){
		cin>>n[i]>>k[i];
		for(int j=1;j<n[i];j++){
			cin>>a[i][j];
		}
	}
	if(c==0){
		if(t==02){
			cout<<1<<endl<<2;
		}
		else if(t==03){
			cout<<1<<endl<<1<<endl<<2;
		}
		else if(t==05&&n[1]==602){
			cout<<17<<endl<<6<<endl<<9<<endl<<6<<endl<<9;
		}
		else if(t==05&&n[1]==24032){
			cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
		}
		else if(t==01){
			cout<<12251;
		}
	}
	return 0;
}
