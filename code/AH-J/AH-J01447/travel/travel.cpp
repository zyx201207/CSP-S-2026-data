#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,cx,br,bc;
	cin>>cr>>br>>cx>>bc;
	ll _1=0,_2=0,_3=0,_4=0;
	if(cr==cx){
		_1=1;
		if(br[0]==bc[0]&&br[1]==bc[1]){
			_2=1;
			ll m=0,n=0;
			if('A'<=br[2]&&br[2]<='C') m=0;
			else m=1;
			if('A'<=bc[2]&&bc[2]<='C') n=0;
			else n=1;
			if(m==n){
				_3=1;
				
				ll cnt=abs(br[2]-bc[2]);
				if(cnt==1){
					_4=1;
				}
				else{
					_4=0;
				}
			}
			else{
				_3=0;
				_4=0;
			}
		}else{
			_2=0;
			_3=0;
			_4=0;
		}
	} 
	else{
		_1=0;
		_2=0;
		_3=0;
		_4=0;
	}
	cout<<_1<<_2<<_3<<_4;
	return 0;
}
