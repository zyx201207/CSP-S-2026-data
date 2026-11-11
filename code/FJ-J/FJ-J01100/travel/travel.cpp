#include<bits/stdc++.h>
#define ll long long
#define rt return
#define ffor(a,b,c,d) for(int (a)=(b);(a)<(c);(a)+=(d))
using namespace std;
int a,b,aa,bb;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>aa>>c>>b>>bb>>d;
	if(a!=b){
		cout<<"0000";
		rt 0;
	}else{
		cout<<1;
		if(aa!=bb){
			cout<<"000";
			rt 0;
		}else{
			cout<<1;
			if(!((c<='C'&&d<='C')||(c>='D'&&d>='D'))){
				cout<<"00";
				rt 0;
			}else{
				cout<<1;
				if(c>d){
					swap(c,d);
				}
				if(c==d-1||(c=='D'&&d=='F')){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
	}
	rt 0;
}
//code by Rufory
//FJ-J01100
