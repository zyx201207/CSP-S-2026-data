#include<bits/stdc++.h> 
using namespace std;
int a[200005];
string ling="0";

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t=0;
	char q;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>q;
		while(a[i]>0){
			ling+=q;
			a[i]--;
		}
	}
	int m=ling.size()-1;
	for(int i=1;i<=m/2;i++){
		if(ling[i]!=ling[m-i+1]){
			//ling[m-i+1]=ling[i];
			t++;
		}
	}
	cout<<t;
	return 0;
}
