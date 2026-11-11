#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		int k;
		string p;
		cin>>k>>p;
		for(int j=1;j<=k;j++){
			s=s+p;
		}
		
	}
	string x=s.substr(0,s.size()/2),y;
	if(s.size()%2==1){
		y=s.substr(s.size()/2+1,s.size()/2);
	}else{
		y=s.substr(s.size()/2,s.size()/2);
	}
	for(int i=0;i<x.size();i++){
		if(x[i]!=y[y.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
 
