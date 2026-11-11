#include<bits/stdc++.h>
using namespace std;
int n;
long long x,s;
char xx,xxl;
string a="0";
bool f=1;
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>xx;
		if(i==1){
			xxl=xx;
		}else{
			if(xx!=xxl){
				f=0;
			}
		}
		while(x){
			x--;
			a+=xx;
		}
	}
	if(f==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=(int((a.size()-1)/2));i++){
		if(a[i]!=a[a.size()-1+1-i]){
			s++;
		}
	}
	cout<<s;
	return 0;
}
