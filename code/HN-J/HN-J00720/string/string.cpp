#include<iostream>
using namespace std;
long long n,num;
struct s{
	int a;
	char c;
}str[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i].a>>str[i].c;
	}
	int l=1,r=n,ls,rs;
	ls=str[l].a;rs=str[r].a;
	while(l<r){
		if(ls>rs){
			if(str[l].c==str[r].c){
				ls-=rs;
				r--;rs=str[r].a;
			}
			else{
				num+=rs;
				ls-=rs;
				r--;rs=str[r].a;
			}
		}
		else if(ls<rs){
			if(str[l].c==str[r].c){
				rs-=ls;
				l++;ls=str[l].a;
			}
			else{
				num+=ls;
				rs-=ls;
				l++;ls=str[l].a;
			}
		}
		else{
			if(str[l].c==str[r].c){
				l++;r--;ls=str[l].a;rs=str[r].a;
			}
			else{
				num+=ls;
				l++;r--;ls=str[l].a;rs=str[r].a;
			}
		}
	}
	cout<<num;
	return 0;
}
