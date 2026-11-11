#include<iostream>
#include<cstring>
using namespace std;
long long n,ii,cd=0,ans=0;
string m;
void it(){
	cin>>n;
	for(int i=1;i<=n;i++){
		char a;
		cin>>ii>>a;
		for(int j=1;j<=ii;j++){
			cd++;
			m[cd]=a;
		}
			
	}
}
void w(){
	if(cd%2==0){
		long long lx=cd/2,rx=cd/2+1,y=cd/2;
		for(long long i=1;i<=y;i++){
			if(m[lx]!=m[rx])
				ans++;
			lx--;
			rx++;
		}
	}
	else{
		long long lx=cd/2,rx=cd/2+2,y=cd/2;
		for(long long i=1;i<=y;i++){
			if(m[lx]!=m[rx])
				ans++;
			lx--;
			rx++;
		}
	}
}
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	it();
	w();
	cout<<ans;
	return 0;
} 
