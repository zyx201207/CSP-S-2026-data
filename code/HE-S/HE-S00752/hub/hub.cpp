#include<bits/stdc++.h>
using namespace std;
freopen("hub.in","r",std.in);
freopen("hub.out","w",std.out);
int main (){
	int c,t;
	int n,k,m,l;
	cin >> c >> t;
	cin >> n >> k;
	int s=0;
	int a,b,q,p;
	for(int i = n-1; i <= n; i ++){
		cin>>a >> b;
		cin>>q>>p;
		if(b==q){
			s+=1;
		}
	}
	cout << s<<endl;
	s=0;
	
	for(int j = 1; j <= m-1; j ++){
	    cin >> m>>l;
	    cin>>q>>p;
		if(l==q){
			s+=1;
		}
	}
	cout <<s;
	return 0;
} 
