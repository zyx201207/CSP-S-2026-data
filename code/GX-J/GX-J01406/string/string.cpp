#include<bits/stdc++.h>
namespace using std;
int main(){
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
		string x,y;
		int n,cnt=0,s;
		cin>>n;
		while(n--){
			int a;
			cin>>a;
			for(int i=1;i<=a;i++){
				cin>>x[i];
				s++;
		}
	}
	for(int i=s-1;i>=0;i--){
		if(i>s/2-1) y[i]=x[s-i];
		else y[i]=x[i];
	}
	for(int i=1;i<=x.size();i++){
		if(x[i]!=y[i]) cnt++;
	}
	cout<<cnt;
		
	return 0;
}		
