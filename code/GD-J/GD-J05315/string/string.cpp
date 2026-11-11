#include <iostream>
using namespace std;
string b;
char a;
long long n,d=0,g=0,s,x=0,m=0,y=0,k,h;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d>>a;
		s=s+d;
		if(d==s){
			for(int f=0;f<d;f++){
				b[f]=a;
				h++;
			}
		}
		else{
			for(int j=k;j<s;j++){
				b[j]=a;
				h++;
			}
		}
		k=d;
	}
	for(int i=h;i<0;i--){
		if(b[i]!=b[x]){
			y++;
		}
		x++;
	}
	cout<<y;
	
	return 0;
}
