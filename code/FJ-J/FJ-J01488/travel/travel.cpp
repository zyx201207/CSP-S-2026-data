#include<iostream>
#include<string>
using namespace std;
bool pd(string a,string b){
	if(a.size()!=b.size()){
		return false;
	}else{
		for(int i=0;i<a.size();i++){
			if(a[i]>='A' and b[i]>='A'){
				break;
			}
			if(a[i]!=b[i]){
				return false;
			}
		}
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string a1,a2,b1,b2,ans;
	cin>>a1>>a2>>b1>>b2;
	if(a2[a2.size()-1]=='F'){
		a2[a2.size()-1]='E';
	}
	if(b2[b2.size()-1]=='F'){
		b2[b2.size()-1]='E';
	}
	ans[0]=ans[1]=ans[2]=ans[3]='0';
	char x=a2[a2.size()-1],y=b2[b2.size()-1];
	if(a1==b1){
		ans[0]='1';
		if(pd(a2,b2)==true){
			ans[1]='1';
			if(x<='C' and y<='C' or x>='D' and y>='D'){
				ans[2]='1';
				if(abs(int(x)-int(y))==1){
					ans[3]='1';
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}
