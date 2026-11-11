#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c,d;
char A,B;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>a>>b>>A>>c>>d>>B;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if(A>='A'&&A<='C'){
				if(B>='A'&&B<='C'){
					cout<<1;
					if(abs(int(A-'A')-int(B-'A'))<=1) cout<<1;
					else cout<<0;
				}
				else cout<<0<<0;
			}else{
				if(B=='D'||B=='F') cout<<1<<1;
				else cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
