#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,sum,res,s;
struct Duan{
	int a;
	char c;
} duan[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	ll l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>duan[i].a>>duan[i].c;
		sum=sum+duan[i].a;
	}
	while(s<sum/2 && l!=r){
		if(duan[l].a>duan[r].a){
			if(duan[l].c!=duan[r].c){
				res=res+duan[r].a;
			}
			s=s+duan[r].a;
			duan[l].a-=duan[r].a;
			r--;
		}else if(duan[l].a<duan[r].a){
			if(duan[l].c!=duan[r].c){
				res=res+duan[l].a;
			}
			s=s+duan[l].a;
			duan[r].a-=duan[l].a;
			l++;	
		}else{
			if(duan[l].c!=duan[r].c){
				res=res+duan[l].a;
			}
			s=s+duan[l].a;
			l++;
			r--;
		}
	}
	cout<<res;
}
