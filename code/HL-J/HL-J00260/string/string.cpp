#include<bits/stdc++.h>
using namespace std;
int n,v,sum=0;
char a,e;
string s;
bool flag=true;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);    
	cin>>n;
    for(int i=0;i<n;i++){
    	cin>>v;
    	cin>>a;
    	if(e!=a){
    		flag=false;
		}else{
			flag=true;
		}
		e=a;
    	for(int j=0;j<v;j++){
    		s[j]=a;
    		sum++;
		}
	}
	if(flag){
		cout<<"0";
		return 0;
	}
	cout<<sum/2;
	return 0;
}